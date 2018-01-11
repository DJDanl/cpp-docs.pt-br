---
title: "Construtores de movimento e operadores de atribuição de movimento (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: move constructor
ms.assetid: e75efe0e-4b74-47a9-96ed-4e83cfc4378d
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 69280eff199b9c04b51bf9b7aa298a67bf31bd89
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="move-constructors-and-move-assignment-operators-c"></a>Operadores de construtores de movimento e de atribuição de movimento (C++)
Este tópico descreve como escrever um *mover construtor* e um operador de atribuição de movimentação de uma classe do C++. Um construtor de movimentação permite que você implemente a semântica de movimentação, que pode melhorar significativamente o desempenho de seus aplicativos. Para obter mais informações sobre a semântica de movimentação, consulte [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
 Este tópico baseia-se na seguinte classe do C++, `MemoryBlock`, que gerencia um buffer de memória.  
  
```cpp  
// MemoryBlock.h  
#pragma once  
#include <iostream>  
#include <algorithm>  
  
class MemoryBlock  
{  
public:  
  
   // Simple constructor that initializes the resource.  
   explicit MemoryBlock(size_t length)  
      : _length(length)  
      , _data(new int[length])  
   {  
      std::cout << "In MemoryBlock(size_t). length = "  
                << _length << "." << std::endl;  
   }  
  
   // Destructor.  
   ~MemoryBlock()  
   {  
      std::cout << "In ~MemoryBlock(). length = "  
                << _length << ".";  
  
      if (_data != nullptr)  
      {  
         std::cout << " Deleting resource.";  
         // Delete the resource.  
         delete[] _data;  
      }  
  
      std::cout << std::endl;  
   }  
  
   // Copy constructor.  
   MemoryBlock(const MemoryBlock& other)  
      : _length(other._length)  
      , _data(new int[other._length])  
   {  
      std::cout << "In MemoryBlock(const MemoryBlock&). length = "   
                << other._length << ". Copying resource." << std::endl;  
  
      std::copy(other._data, other._data + _length, _data);  
   }  
  
   // Copy assignment operator.  
   MemoryBlock& operator=(const MemoryBlock& other)  
   {  
      std::cout << "In operator=(const MemoryBlock&). length = "   
                << other._length << ". Copying resource." << std::endl;  
  
      if (this != &other)  
      {  
         // Free the existing resource.  
         delete[] _data;  
  
         _length = other._length;  
         _data = new int[_length];  
         std::copy(other._data, other._data + _length, _data);  
      }  
      return *this;  
   }  
  
   // Retrieves the length of the data resource.  
   size_t Length() const  
   {  
      return _length;  
   }  
  
private:  
   size_t _length; // The length of the resource.  
   int* _data; // The resource.  
};  
```  
  
 Os procedimentos a seguir descrevem como escrever um construtor de movimentação e um operador de atribuição de movimentação para o exemplo de classe C++.  
  
### <a name="to-create-a-move-constructor-for-a-c-class"></a>Para criar um construtor de movimentação para a classe C++  
  
1.  Defina um método de construtor vazio que obtenha uma referência rvalue para o tipo de classe como seu parâmetro, como demonstrado no exemplo a seguir:  
  
    ```cpp  
    MemoryBlock(MemoryBlock&& other)  
       : _data(nullptr)  
       , _length(0)  
    {  
    }  
    ```  
  
2.  No construtor de movimentação, atribua os membros de dados de classe do objeto de origem para o objeto sendo construído:  
  
    ```cpp  
    _data = other._data;  
    _length = other._length;  
    ```  
  
3.  Atribua os membros de dados do objeto de origem para os valores padrão. Isso impede que o destruidor libere recursos (como a memória) várias vezes:  
  
    ```cpp  
    other._data = nullptr;  
    other._length = 0;  
    ```  
  
### <a name="to-create-a-move-assignment-operator-for-a-c-class"></a>Para criar um operador de atribuição de movimentação para a classe C++  
  
1.  Defina um operador de atribuição vazio que pegue uma referência rvalue para o tipo de classe como seu parâmetro e retorne uma referência para o tipo de classe, como demonstrado no exemplo a seguir:  
  
    ```cpp  
    MemoryBlock& operator=(MemoryBlock&& other)  
    {  
    }  
    ```  
  
2.  No operador de atribuição de movimentação, adicione uma instrução condicional que não execute nenhuma operação se você tentar atribuir o objeto a ele mesmo.  
  
    ```cpp  
    if (this != &other)  
    {  
    }  
    ```  
  
3.  Na instrução condicional, libere quaisquer recursos (como a memória) do objeto ao qual ela está sendo atribuída.  
  
     O exemplo a seguir libera o membro `_data` do objeto ao qual está sendo atribuído:  
  
    ```cpp  
    // Free the existing resource.  
    delete[] _data;  
    ```  
  
     Siga as etapas 2 e 3 no primeiro procedimento para transferir os membros de dados do objeto de origem para o objeto sendo construído:  
  
    ```cpp  
    // Copy the data pointer and its length from the   
    // source object.  
    _data = other._data;  
    _length = other._length;  
  
    // Release the data pointer from the source object so that  
    // the destructor does not free the memory multiple times.  
    other._data = nullptr;  
    other._length = 0;  
    ```  
  
4.  Retorne uma referência para o objeto atual, conforme mostrado no exemplo a seguir:  
  
    ```cpp  
    return *this;  
    ```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra o construtor de movimentação completo e o operador de atribuição de movimentação para a classe `MemoryBlock`:  
  
```cpp  
// Move constructor.  
MemoryBlock(MemoryBlock&& other)  
   : _data(nullptr)  
   , _length(0)  
{  
   std::cout << "In MemoryBlock(MemoryBlock&&). length = "   
             << other._length << ". Moving resource." << std::endl;  
  
   // Copy the data pointer and its length from the   
   // source object.  
   _data = other._data;  
   _length = other._length;  
  
   // Release the data pointer from the source object so that  
   // the destructor does not free the memory multiple times.  
   other._data = nullptr;  
   other._length = 0;  
}  
  
// Move assignment operator.  
MemoryBlock& operator=(MemoryBlock&& other)  
{  
   std::cout << "In operator=(MemoryBlock&&). length = "   
             << other._length << "." << std::endl;  
  
   if (this != &other)  
   {  
      // Free the existing resource.  
      delete[] _data;  
  
      // Copy the data pointer and its length from the   
      // source object.  
      _data = other._data;  
      _length = other._length;  
  
      // Release the data pointer from the source object so that  
      // the destructor does not free the memory multiple times.  
      other._data = nullptr;  
      other._length = 0;  
   }  
   return *this;  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como a semântica de movimentação pode melhorar o desempenho de seus aplicativos. O exemplo adiciona dois elementos a um objeto de vetor e insere um novo elemento entre os dois elementos existentes. No Visual C++ 2010, o `vector` usa classe move semântica para executar a operação de inserção com eficiência ao mover os elementos de vetor em vez de copiá-los.  
  
```cpp  
// rvalue-references-move-semantics.cpp  
// compile with: /EHsc  
#include "MemoryBlock.h"  
#include <vector>  
  
using namespace std;  
  
int main()  
{  
   // Create a vector object and add a few elements to it.  
   vector<MemoryBlock> v;  
   v.push_back(MemoryBlock(25));  
   v.push_back(MemoryBlock(75));  
  
   // Insert a new element into the second position of the vector.  
   v.insert(v.begin() + 1, MemoryBlock(50));  
}  
```  
  
 Este exemplo gera a seguinte saída:  
  
```  
In MemoryBlock(size_t). length = 25.  
In MemoryBlock(MemoryBlock&&). length = 25. Moving resource.  
In ~MemoryBlock(). length = 0.  
In MemoryBlock(size_t). length = 75.  
In MemoryBlock(MemoryBlock&&). length = 25. Moving resource.  
In ~MemoryBlock(). length = 0.  
In MemoryBlock(MemoryBlock&&). length = 75. Moving resource.  
In ~MemoryBlock(). length = 0.  
In MemoryBlock(size_t). length = 50.  
In MemoryBlock(MemoryBlock&&). length = 50. Moving resource.  
In MemoryBlock(MemoryBlock&&). length = 50. Moving resource.  
In operator=(MemoryBlock&&). length = 75.  
In operator=(MemoryBlock&&). length = 50.  
In ~MemoryBlock(). length = 0.  
In ~MemoryBlock(). length = 0.  
In ~MemoryBlock(). length = 25. Deleting resource.  
In ~MemoryBlock(). length = 50. Deleting resource.  
In ~MemoryBlock(). length = 75. Deleting resource.  
```  
  
 Antes de Visual C++ 2010, este exemplo produz a seguinte saída:  
  
```  
In MemoryBlock(size_t). length = 25.  
In MemoryBlock(const MemoryBlock&). length = 25. Copying resource.  
In ~MemoryBlock(). length = 25. Deleting resource.  
In MemoryBlock(size_t). length = 75.  
In MemoryBlock(const MemoryBlock&). length = 25. Copying resource.  
In ~MemoryBlock(). length = 25. Deleting resource.  
In MemoryBlock(const MemoryBlock&). length = 75. Copying resource.  
In ~MemoryBlock(). length = 75. Deleting resource.  
In MemoryBlock(size_t). length = 50.  
In MemoryBlock(const MemoryBlock&). length = 50. Copying resource.  
In MemoryBlock(const MemoryBlock&). length = 50. Copying resource.  
In operator=(const MemoryBlock&). length = 75. Copying resource.  
In operator=(const MemoryBlock&). length = 50. Copying resource.  
In ~MemoryBlock(). length = 50. Deleting resource.  
In ~MemoryBlock(). length = 50. Deleting resource.  
In ~MemoryBlock(). length = 25. Deleting resource.  
In ~MemoryBlock(). length = 50. Deleting resource.  
In ~MemoryBlock(). length = 75. Deleting resource.  
```  
  
 A versão deste exemplo que usa a semântica de movimentação é mais eficiente do que a versão que não usa a semântica de movimentação, pois ela executa menos operações de cópia, alocação de memória e desalocação de memória.  
  
## <a name="robust-programming"></a>Programação robusta  
 Para evitar vazamento de recursos, sempre libere recursos (como a memória, os identificadores de arquivo e os soquetes) no operador de atribuição de movimentação.  
  
 Para evitar a destruição irrecuperável de recursos, manipule corretamente a autoatribuição no operador de atribuição de movimentação.  
  
 Se você fornecer um construtor de movimentação e um operador de atribuição de movimentação de sua classe, poderá eliminar o código supérfluo escrevendo o construtor de movimentação para chamar o operador de atribuição de movimentação. O exemplo a seguir mostra uma versão revisada do construtor de movimentação que chama o operador de atribuição de movimentação:  
  
```  
// Move constructor.  
MemoryBlock(MemoryBlock&& other)  
   : _data(nullptr)  
   , _length(0)  
{  
   *this = std::move(other);  
}  
```  
  
 O [std::move](../standard-library/utility-functions.md#move) função preserva a propriedade rvalue o `other` parâmetro.  
  
## <a name="see-also"></a>Consulte também  
 [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md)   
 [\<utilitário > Mover](http://msdn.microsoft.com/en-us/abef7e85-9dd6-4724-85da-d7f7fe95dca9)