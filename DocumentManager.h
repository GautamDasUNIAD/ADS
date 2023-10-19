#ifndef DOCUMENTMANAGER
#define DOCUMENTMANAGER
// for the patron ids
#include <unordered_set>
// for the document names and ids
#include <unordered_map>
// for the document ids and licensing
#include <vector>
// for document names
#include <string>

class DocumentManager {
private:
  // using a un_ordered set for patron ids becasue the
  // only usage in this context is to see if the patron
  // id exists. Since the un-ordered set provides O(1)
  // look up time it is useful here.
  // the other option is using a array/vector and
  // the reason for not using array/vector is that is that
  // ids may not have a defined order or could have gaps
  // for a reason such as: ids with a given prefix (eg. 999)
  // have different permissions. In such a case, extra space
  // is needed when using a array/vector
  std::unordered_set<int> patron_ids;
  // as per the given description, the only use for the
  // document name is to check if the document exists
  // (lookup) and provide to corressponding id (relate it
  // to id). An unordered_map provides the O(k) lookup time
  // (on average, k is the length of the string)
  // and instantly provides the id, it has been used here
  std::unordered_map<std::string, int> document_names_ids;
  // based on the description, the doc_licensing needs to
  // be accessible via the doc_id. and currently, that is
  // the only use of the doc_id (using it to look up)
  // hence a un_ordered map can be used with the doc_id as
  // the key, to ahve O(1) and the value can be an array
  // with two values (the max licences and current lincences).
  // Since the index of the max and current lincenses is
  // known and constant, once the looked up, they can be retrived
  // in constant time and stored in minimum space
  // An ordered map is being used instead of a vector/array
  // because the ids may not be in order, documents that
  // have a certain prefix may be related to certain topics
  std::unordered_map<int, int[2]> document_ids_licensing;

public:
  // constructor function
  DocumentManager();
  // function to add a document
  void addDocument(std::string name, int id, int license_limit);
  // function to add a patron
  void addPatron(int patronID);
  // returns docid if name is in the document collection or 0 if the name is not
  // in the collection
  int search(std::string name);
  // returns true if document is borrowed, false if it can not be borrowed
  // (invalid patronid or the number of copies current borrowed has
  // reached the license limit)
  bool borrowDocument(int docid, int patronID);
  // function to return a document
  void returnDocument(int docid, int patronID);
};
#endif