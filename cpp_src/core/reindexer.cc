#include "core/reindexer.h"
#include "core/reindexerimpl.h"

namespace reindexer {

Reindexer::Reindexer() { impl_ = new ReindexerImpl(); }
Reindexer::~Reindexer() { delete impl_; }
Error Reindexer::Connect(const string& dsn) { return impl_->Connect(dsn); }
Error Reindexer::EnableStorage(const string& storagePath, bool skipPlaceholderCheck) {
	return impl_->EnableStorage(storagePath, skipPlaceholderCheck);
}
Error Reindexer::AddNamespace(const NamespaceDef& nsDef) { return impl_->AddNamespace(nsDef); }
Error Reindexer::OpenNamespace(string_view nsName, const StorageOpts& storage) { return impl_->OpenNamespace(nsName, storage); }
Error Reindexer::DropNamespace(string_view nsName) { return impl_->DropNamespace(nsName); }
Error Reindexer::CloseNamespace(string_view nsName) { return impl_->CloseNamespace(nsName); }
Error Reindexer::Insert(string_view nsName, Item& item, Completion cmpl) { return impl_->Insert(nsName, item, cmpl); }
Error Reindexer::Update(string_view nsName, Item& item, Completion cmpl) { return impl_->Update(nsName, item, cmpl); }
Error Reindexer::Upsert(string_view nsName, Item& item, Completion cmpl) { return impl_->Upsert(nsName, item, cmpl); }
Error Reindexer::Delete(string_view nsName, Item& item, Completion cmpl) { return impl_->Delete(nsName, item, cmpl); }
Item Reindexer::NewItem(string_view nsName) { return impl_->NewItem(nsName); }
Transaction Reindexer::NewTransaction(string_view nsName) { return impl_->NewTransaction(nsName.ToString()); }
Error Reindexer::CommitTransaction(Transaction& tr) { return impl_->CommitTransaction(tr); }
Error Reindexer::RollBackTransaction(Transaction& tr) { return impl_->RollBackTransaction(tr); }
Error Reindexer::GetMeta(string_view nsName, const string& key, string& data) { return impl_->GetMeta(nsName, key, data); }
Error Reindexer::PutMeta(string_view nsName, const string& key, const string_view& data) { return impl_->PutMeta(nsName, key, data); }
Error Reindexer::EnumMeta(string_view nsName, vector<string>& keys) { return impl_->EnumMeta(nsName, keys); }
Error Reindexer::Delete(const Query& q, QueryResults& result) { return impl_->Delete(q, result); }
Error Reindexer::Select(string_view query, QueryResults& result, Completion cmpl) { return impl_->Select(query, result, cmpl); }
Error Reindexer::Select(const Query& q, QueryResults& result, Completion cmpl) { return impl_->Select(q, result, cmpl); }
Error Reindexer::Update(const Query& query, QueryResults& result) { return impl_->Update(query, result); }
Error Reindexer::Commit(string_view nsName) { return impl_->Commit(nsName); }
Error Reindexer::AddIndex(string_view nsName, const IndexDef& idx) { return impl_->AddIndex(nsName, idx); }
Error Reindexer::UpdateIndex(string_view nsName, const IndexDef& idx) { return impl_->UpdateIndex(nsName, idx); }
Error Reindexer::DropIndex(string_view nsName, const IndexDef& index) { return impl_->DropIndex(nsName, index); }
Error Reindexer::EnumNamespaces(vector<NamespaceDef>& defs, bool bEnumAll) { return impl_->EnumNamespaces(defs, bEnumAll); }
Error Reindexer::InitSystemNamespaces() { return impl_->InitSystemNamespaces(); }
Error Reindexer::SubscribeUpdates(IUpdatesObserver* observer, bool subscribe) { return impl_->SubscribeUpdates(observer, subscribe); }
Error Reindexer::GetSqlSuggestions(const string_view sqlQuery, int pos, vector<string>& suggestions) {
	return impl_->GetSqlSuggestions(sqlQuery, pos, suggestions);
}

}  // namespace reindexer
