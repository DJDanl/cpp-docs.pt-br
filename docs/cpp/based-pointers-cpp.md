---
title: Com base em ponteiros (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- __based
- __based_cpp
dev_langs:
- C++
helpviewer_keywords:
- __based keyword [C++]
- based pointers
- pointers, based
ms.assetid: 1e5f2e96-c52e-4738-8e14-87278681205e
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 629ff6c3f383973b758ddb4317e43a27de0b11d3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="based-pointers-c"></a>Ponteiros baseados (C++)
**Seção específica da Microsoft**  
  
 A palavra-chave `__based` permite declarar ponteiros baseados em ponteiros (ponteiros que são deslocamentos de ponteiros existentes).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
type __based( base ) declarator   
```  
  
## <a name="remarks"></a>Comentários  
 Os ponteiros baseados em endereços de ponteiros são o único formato da palavra-chave `__based` válido em compilações de 32 bits e de 64 bits. Para os compiladores C/C++ de 32 bits da Microsoft, um ponteiro baseado é um deslocamento de 32 bits de uma base de ponteiro de 32 bits. Uma restrição semelhante é mantida para ambientes de 64 bits, onde um ponteiro baseado é um deslocamento de 64 bits da base de 64 bits.  
  
 Um uso para ponteiros baseados em ponteiros é para identificadores persistentes que contêm ponteiros. Uma lista vinculada que consiste em ponteiros baseados em um ponteiro pode ser salva em disco e depois ser recarregada em outro local na memória, com os ponteiros permanecendo válidos. Por exemplo:  
  
```  
// based_pointers1.cpp  
// compile with: /c  
void *vpBuffer;  
struct llist_t {  
   void __based( vpBuffer ) *vpData;  
   struct llist_t __based( vpBuffer ) *llNext;  
};  
```  
  
 O ponteiro `vpBuffer` é atribuído ao endereço da memória alocada em algum momento posterior no programa. A lista vinculada é realocada em relação ao valor de `vpBuffer`.  
  
> [!NOTE]
>  Persistindo identificadores que contém ponteiros também podem ser feitos usando [arquivos mapeados na memória](http://msdn.microsoft.com/library/windows/desktop/aa366556).  
  
 Ao desreferenciar um ponteiro baseado, a base deve ser especificada explicitamente ou implicitamente conhecida na declaração.  
  
 Para compatibilidade com versões anteriores, **_based** é um sinônimo para `__based`.  
  
## <a name="example"></a>Exemplo  
 O código a seguir demonstra a alteração de um ponteiro baseado alterando sua base.  
  
```  
// based_pointers2.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int a1[] = { 1,2,3 };  
int a2[] = { 10,11,12 };  
int *pBased;  
  
typedef int __based(pBased) * pBasedPtr;  
  
using namespace std;  
int main() {  
   pBased = &a1[0];  
   pBasedPtr pb = 0;  
  
   cout << *pb << endl;  
   cout << *(pb+1) << endl;  
  
   pBased = &a2[0];  
  
   cout << *pb << endl;  
   cout << *(pb+1) << endl;  
}  
```  
  
```Output  
1  
2  
10  
11  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [alloc_text](../preprocessor/alloc-text.md)