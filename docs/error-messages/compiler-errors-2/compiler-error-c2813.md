---
title: C2813 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: C2813
ms.assetid: 6cf2135f-7b82-42d1-909a-5e864308a09c
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3cc6ac0e287894dc2202814c55dac37569650f5e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2813"></a>C2813 de erro do compilador
\#importação não é suportada com /MP  
  
 C2813 é emitida se um comando de compilador que você especificar o **/MP** contém a opção de compilador e dois ou mais arquivos de compilação e um ou mais dos arquivos de[#import](../../preprocessor/hash-import-directive-cpp.md) diretiva de pré-processamento. O [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva gera classes C++ dos tipos na biblioteca do tipo especificado e, em seguida, grava essas classes dois arquivos de cabeçalho. O [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva não tem suporte porque se várias unidades de compilação importar a mesma biblioteca de tipos, essas unidades de conflito ao tentar gravar os mesmos arquivos de cabeçalho ao mesmo tempo.  
  
 Esse erro de compilador e o **/MP** opção de compilador são novos no Visual Studio 2008.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2813. Linha de comando na "compilar com:" comentário indica para o compilador para usar o **/MP** e **/c** opções do compilador para compilar arquivos diversos. Pelo menos um dos arquivos contém o [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva. Podemos usar o mesmo arquivo duas vezes para testar este exemplo.  
  
```  
// C2813.cpp  
// compile with: /MP /c C2813.cpp C2813.cpp  
#import "C:\windows\system32\stdole2.tlb"   // C2813  
int main()   
{  
}  
```