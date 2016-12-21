---
title: "Aviso do compilador (n&#237;vel 1) C4291 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4291"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4291"
ms.assetid: c2b95dea-38f2-4609-9104-707c30798da4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4291
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“declaração”: nenhuma exclusão correspondente do operador localizada; a memória não será lançada se a inicialização gerará uma exceção  
  
 Uma colocação [novo](../../cpp/new-operator-cpp.md) é usada para o qual não há nenhuma posicionamento [excluir](../../cpp/delete-operator-cpp.md).  
  
 Quando a memória alocada para um objeto com o operador **new**, o construtor do objeto é chamado.  Se o construtor gerou uma exceção, toda a memória que é atribuída ao objeto deve ser desalocada.  Isso não ocorrer a menos que uma função de **delete** do operador existentes que corresponde ao operador **new**.  
  
 Se você usar o operador **new** sem argumentos adicionais e o compila com [\/GX](../Topic/-GX%20\(Enable%20Exception%20Handling\).md), [\/EHs](../../build/reference/eh-exception-handling-model.md), ou opções de \/EHa habilitar a manipulação de exceções, o compilador gerará o código para chamar o operador **delete** se o construtor gerencie uma exceção.  
  
 Se você usar o formato de posicionamento do operador de **new** \(o formulário com argumentos além do tamanho da alocação\) e o construtor do objeto gerou uma exceção, o compilador ainda gerará o código para chamar o operador **delete**; mas fará isso só se uma forma de posicionamento do operador **delete** existe correspondendo o formulário de posicionamento do operador **new** que alocou a memória.  Por exemplo:  
  
```  
// C4291.cpp  
// compile with: /EHsc /W1  
#include <malloc.h>  
  
class CList  
{  
public:  
   CList(int)  
   {  
      throw "Fail!";  
   }  
};  
  
void* operator new(size_t size, char* pszFilename, int nLine)  
{  
   return malloc(size);  
}  
  
int main(void)  
{  
   try  
   {  
      // This will call ::operator new(unsigned int) to allocate heap  
      // memory. Heap memory pointed to by pList1 will automatically be  
      // deallocated by a call to ::operator delete(void*) when  
      // CList::CList(int) throws an exception.  
      CList* pList1 = new CList(10);  
   }  
   catch (...)  
   {  
   }  
  
   try  
   {  
      // This will call the overloaded ::operator new(size_t, char*, int)  
      // to allocate heap memory. When CList::CList(int) throws an  
      // exception, ::operator delete(void*, char*, int) should be called  
      // to deallocate the memory pointed to by pList2. Since  
      // ::operator delete(void*, char*, int) has not been implemented,  
      // memory will be leaked when the deallocation cannot occur.  
      CList* pList2 = new(__FILE__, __LINE__) CList(20);   // C4291  
   }  
   catch (...)  
   {  
   }  
}  
```  
  
 O exemplo anterior gerenciar C4291 de aviso porque nenhuma forma de posicionamento do operador **delete** foi definido que corresponde ao formato de posicionamento do operador **new**.  Para resolver o problema, insira o seguinte código acima de **main**.  Observe que todos os parâmetros sobrecarregados da função de **delete** do operador correspondem às opções do operador sobrecarregado **new**, com exceção do primeiro parâmetro.  
  
```  
void operator delete(void* pMem, char* pszFilename, int nLine)  
{  
   free(pMem);  
}  
```