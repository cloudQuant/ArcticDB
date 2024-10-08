#include <arcticdb/util/buffer_holder.hpp>
#include <arcticdb/column_store/column.hpp>
#include <arcticdb/entity/types.hpp>

namespace arcticdb {
std::shared_ptr<Column> BufferHolder::get_buffer(const TypeDescriptor& td, entity::Sparsity allow_sparse) {
    std::lock_guard lock(mutex_);
    auto column = std::make_shared<Column>(td, allow_sparse);
    columns_.emplace_back(column);
    return column;
}
} //namespace arcticdb

