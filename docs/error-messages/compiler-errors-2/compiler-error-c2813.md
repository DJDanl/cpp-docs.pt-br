---
title: C2813 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- C2813
ms.assetid: 6cf2135f-7b82-42d1-909a-5e864308a09c
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5cdfa3133ca62c6d923ac2fdae973822669fe11c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2813"></a>C2813 de erro do compilador
\#Não há suporte para importação /MP  
  
 C2813 é emitida se um comando de compilador que você especificar o **/MP** contém a opção de compilador e dois ou mais arquivos de compilação e um ou mais arquivos de[#import](../../preprocessor/hash-import-directive-cpp.md) diretiva de pré-processamento. O [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva gera classes C++ dos tipos na biblioteca de tipos especificada e grava essas classes em dois arquivos de cabeçalho. O [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva não tem suporte porque se várias unidades de compilação importar a mesma biblioteca de tipos, essas unidades estão em conflito ao tentar gravar os mesmos arquivos de cabeçalho ao mesmo tempo.  
  
 Esse erro de compilador e o **/MP** opção de compilador são novos no [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)].  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2813. Linha de comando na "compilar com:" comentário indica ao compilador para usar o **/MP** e **/c** opções do compilador para compilar vários arquivos. Pelo menos um dos arquivos contém o [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva. Podemos usar o mesmo arquivo duas vezes para fins de teste, este exemplo.  
  
```  
// C2813.cpp  
// compile with: /MP /c C2813.cpp C2813.cpp  
#import "C:\windows\system32\stdole2.tlb"   // C2813  
int main()   
{  
}  
```
