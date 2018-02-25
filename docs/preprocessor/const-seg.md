---
title: const_seg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.const_seg
- const_seg_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, const_seg
- const_seg pragma
ms.assetid: 1eb58ee2-fb0e-4a39-9621-699c8f5ef957
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c4c87ee9f0e867223186868de0ef2b39203c3710
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="constseg"></a>const_seg
Especifica o segmento onde [const](../cpp/const-cpp.md) variáveis são armazenadas no arquivo. obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma const_seg ( [ [ { push | pop}, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## <a name="remarks"></a>Comentários  
 O significado dos termos de *segmento* e *seção* são intercambiáveis neste tópico.  
  
 Arquivos OBJ podem ser exibidos com o [dumpbin](../build/reference/dumpbin-command-line.md) aplicativo. O segmento padrão no arquivo. obj para `const` variáveis é RDATA. Alguns `const` como escalares, as variáveis são automaticamente embutidas no fluxo de código. O código embutido não aparecerá em .rdata.  
  
 Define um objeto que requerem inicialização dinâmica em um `const_seg` resulta em um comportamento indefinido.  
  
 `#pragma const_seg` sem parâmetros redefine o segmento para RDATA.  
  
 `push` (opcional)  
 Coloca um registro na pilha interna do compilador. Um `push` pode ter um `identifier` e `segment-name`.  
  
 `pop` (opcional)  
 Remove um registro do topo da pilha interna do compilador.  
  
 `identifier` (opcional)  
 Quando usado com `push`, atribui um nome ao registro na pilha interna do compilador. Quando usado com `pop`, elimina registros da pilha interna até que `identifier` seja removido; se `identifier` não for localizado na pilha interna, nada será exibido.  
  
 Usando `identifier` permite que vários registros deve ser exibido com um único `pop` comando.  
  
 "`segment-name`" (opcional)  
 O nome de um segmento. Quando usado com `pop`, a pilha é exibida e `segment-name` se torna o nome de segmento ativo.  
  
 "`segment-class`" (opcional)  
 Incluído para compatibilidade com o C++ antes da versão 2.0. É ignorado.  
  
## <a name="example"></a>Exemplo  
  
```  
// pragma_directive_const_seg.cpp  
// compile with: /EHsc  
#include <iostream>  
  
const int i = 7;               // inlined, not stored in .rdata  
const char sz1[]= "test1";     // stored in .rdata  
  
#pragma const_seg(".my_data1")  
const char sz2[]= "test2";     // stored in .my_data1  
  
#pragma const_seg(push, stack1, ".my_data2")  
const char sz3[]= "test3";     // stored in .my_data2  
  
#pragma const_seg(pop, stack1) // pop stack1 from stack  
const char sz4[]= "test4";     // stored in .my_data1  
  
int main() {  
    using namespace std;  
   // const data must be referenced to be put in .obj  
   cout << sz1 << endl;  
   cout << sz2 << endl;  
   cout << sz3 << endl;  
   cout << sz4 << endl;  
}  
```  
  
```Output  
test1  
test2  
test3  
test4  
```  
  
## <a name="comments"></a>Comentários  
 Consulte [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.  
  
 Você também pode especificar seções de dados inicializado ([data_seg](../preprocessor/data-seg.md)), dados foi cancelada ([bss_seg](../preprocessor/bss-seg.md)) e funções ([code_seg](../preprocessor/code-seg.md)).  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)