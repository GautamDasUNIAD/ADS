#include "DocumentManager.h"

// constructor function
DocumentManager::DocumentManager(){};
// function to add a document
void DocumentManager::addDocument(std::string name, int id, int license_limit) {
  // Add name and id to the map for document names and ids
  document_names_ids.emplace(name, id);
  // Add id and license limit to the map for document ids and license limits
  document_ids_licensing[id][0] = 0; // the current number of licences
  document_ids_licensing[id][1] = license_limit; // the max number of licenses
}
// function to add a patron
void DocumentManager::addPatron(int patronID) {
  // Add the patron id to the set
  patron_ids.emplace(patronID);
}
// returns docid if name is in the document collection or 0 if the name is not
// in the collection
int DocumentManager::search(std::string name) {
  // lookup string in the map
  auto it = document_names_ids.find(name);
  // if the string wasn't found
  if (it == document_names_ids.end())
    return 0;
  else
    // return the id
    return it->second;
}
// returns true if document is borrowed, false if it can not be borrowed
// (invalid patronid or the number of        copies current borrowed has
// reached the license limit)
bool DocumentManager::borrowDocument(int docid, int patronID) {
  // see if the docid is in the collection
  // lookup id in the map
  auto it = document_ids_licensing.find(docid);
  // if the id wasn't found
  if (it == document_ids_licensing.end())
    return false;
  else{
    // check if patron id exists
    auto patron_it = patron_ids.find(patronID);
    // if the string wasn't found
    if (patron_it == patron_ids.end())
      return false;
    else
      // if the number of licences is less than the max
      if (it->second[0] < it->second[1]) {
        // update the number of current licenses
        it->second[0] = it->second[0] + 1;
        return true;
      } else {
        return false;
      }
  }
}
// function to return a document
void DocumentManager::returnDocument(int docid, int patronID) {
  // see if the docid is in the collection
  // lookup id in the map
  auto it = document_ids_licensing.find(docid);
  // if the id is found
  if (it != document_ids_licensing.end())
    it->second[0] = it->second[0] - 1;
}
