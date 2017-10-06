---
title: operador de uuidof | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __LIBID_cpp
- __uuidof_cpp
dev_langs:
- C++
helpviewer_keywords:
- __uuidof keyword [C++]
- __LIBID_ keyword [C++]
ms.assetid: badfe709-809b-4b66-ad48-ee35039d25c6
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 172ed545eb2c46db8df12e3e12a2296a5f172a1f
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="uuidof-operator"></a>Operador __uuidof
**Seção específica da Microsoft**  
  
 Recupera o GUID vinculado à expressão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      __uuidof (  
   expression   
)  
```  
  
## <a name="remarks"></a>Comentários  
 O *expressão* pode ser um nome de tipo, ponteiro, referência ou matriz desse tipo, um modelo especializado sobre esses tipos, ou uma variável desses tipos. O argumento é válido enquanto o compilador puder usá-lo para localizar o GUID vinculado.  
  
 Um caso especial de nesse intrínseco é quando o **0** ou **nulo** for fornecida como argumento. Nesse caso, `__uuidof` retornará um GUID composto de zero.  
  
 Use essa palavra-chave para extrair o GUID vinculado a:  
  
-   Um objeto de [uuid](../cpp/uuid-cpp.md) atributos estendidos.  
  
-   Um bloco de biblioteca criado com o [módulo](../windows/module-cpp.md) atributo.  
  
> [!NOTE]
>  Em uma compilação de depuração, `__uuidof` sempre inicializa um objeto dinamicamente (no tempo de execução). Em uma compilação de versão, `__uuidof` pode inicializar um objeto estaticamente (no tempo de compilação).  
  
## <a name="example"></a>Exemplo  
 O código a seguir (compilado com ole32.lib) exibirá o uuid de um bloco de biblioteca criado com o atributo module:  
  
```  
// expre_uuidof.cpp  
// compile with: ole32.lib  
#include "stdio.h"  
#include "windows.h"  
  
[emitidl];  
[module(name="MyLib")];  
[export]  
struct stuff {  
   int i;  
};  
  
int main() {  
   LPOLESTR lpolestr;  
   StringFromCLSID(__uuidof(MyLib), &lpolestr);  
   wprintf_s(L"%s", lpolestr);  
   CoTaskMemFree(lpolestr);  
}  
```  
  
## <a name="comments"></a>Comentários  
 Em casos onde o nome da biblioteca não está no escopo, você pode usar __LIBID\_ em vez de `__uuidof`. Por exemplo:  
  
```  
StringFromCLSID(__LIBID_, &lpolestr);  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
