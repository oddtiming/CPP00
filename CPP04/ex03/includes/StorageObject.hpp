#ifndef STORAGE_OBJECT_HPP_
# define STORAGE_OBJECT_HPP_

# include "AMateria.hpp"

# define STORAGE_MAX 4096

class StorageObject {
	private:
		/* Attributes */
		AMateria *		_storage[STORAGE_MAX];
		uint			_nbStored;

	public:
		StorageObject( );
		StorageObject( StorageObject const & src );
		
		~StorageObject( );

		StorageObject &	operator=( StorageObject const & rhs );

		bool	addMateria( AMateria * newM );
		void	deleteStorage( );

};

#endif // STORAGE_OBJECT_HPP_