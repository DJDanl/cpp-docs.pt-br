---
title: "-Zc: inline (remover COMDAT não referenciado) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /Zc:inline
- VC.Project.VCCLCompilerTool.RemoveUnreferencedCodeData
dev_langs: C++
helpviewer_keywords:
- -Zc compiler options (C++)
- /Zc compiler options (C++)
- Zc compiler options (C++)
- /Zc:inline
ms.assetid: a4c94224-1d73-4bea-a9d5-4fa73dc924df
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 7031a5f7a92a6775718b77ea20a69623ae3066c9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="zcinline-remove-unreferenced-comdat"></a>/Zc:inline (remover COMDAT não referenciado)
Remove funções não referenciadas ou dados que sejam COMDATs ou que tenham apenas vínculo interno. Quando **/ZC: inline** for especificado, o compilador requer que as unidades de tradução que usam dados embutidos ou funções embutidas também devem incluir as definições para as funções ou dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zc:inline[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Quando **/ZC: inline** for especificado, o compilador não emitir informações de símbolo para funções COMDAT não referenciadas ou dados, ou para funções ou dados que tiverem apenas ligação interna. Por padrão, essa opção está desativada (**/Zc:inline-**). Essa otimização simplifica a parte do trabalho executado pelo vinculador nas compilações de lançamento ou quando a opção de vinculador [/OPT: REF](../../build/reference/opt-optimizations.md) for especificado. Ao realizar essa otimização, o compilador pode reduzir significativamente o tamanho do arquivo .obj e aumentar as velocidades do vinculador. Essa opção de compilador não está habilitada quando as otimizações são desabilitadas ([/Od](../../build/reference/od-disable-debug.md)) ou quando [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md) for especificado.  
  
 Se **/ZC: inline** for especificado, o compilador aplica o C++ 11 requisito de que todas as funções declaradas `inline` deve ter uma definição disponível na unidade de tradução mesmo se eles são usados. Quando a opção não é especificada, o [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] permite o código em não conformidade que invoca as funções declaradas `inline`, mesmo que não haja uma definição visível. Para obter mais informações, consulte o padrão do C++11, nas seções 3.2 e 7.1.2. Essa opção do compilador foi introduzida no Visual Studio 2013 Atualização 2.  
  
 Para usar o **/ZC: inline** opção, o código de não conformidade de atualização. Este exemplo mostra como o uso de não conformidade de uma declaração de função embutida sem uma definição ainda compila e vincula quando o padrão **/Zc:inline-** opção é usada:  
  
```cpp  
// example.h  
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp  
#pragma once  
  
class Example {  
public:  
   inline void inline_call(); // declared but not defined inline  
   void normal_call();  
   Example() {};  
};  
```  
  
```cpp  
// example.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp  
#include <stdio.h>  
#include "example.h"  
  
void Example::inline_call() {  
   printf("inline_call was called.\n");   
}  
  
void Example::normal_call() {  
   printf("normal_call was called.\n");   
   inline_call(); // with /Zc:inline-, inline_call forced into .obj file  
}  
```  
  
```cpp  
// zcinline.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline.cpp example.cpp  
#include "example.h"  
  
void main() {  
   Example example;  
   example.inline_call(); // normal call when definition unavailable  
}  
```  
  
 Quando **/ZC: inline** estiver habilitado, o mesmo código que faz com que um [LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md) erro, porque o compilador não emite um corpo de código não embutida para `Example::inline_call` em example.obj. Isso faz a chamada não embutida em `main` mencionar um símbolo externo indefinido.  
  
 Para resolver esse erro, é possível remover a palavra-chave `inline` da declaração de `Example::inline_call`, mover a definição de `Example::inline_call` para o arquivo de cabeçalho ou mover a implementação de `Example` para main.cpp. O próximo exemplo move a definição para o arquivo de cabeçalho, onde ele permanece visível para qualquer chamador com o cabeçalho.  
  
```cpp  
// example2.h  
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp  
#pragma once  
#include <stdio.h>  
  
class Example2 {  
public:  
   inline void inline_call() {  
      printf("inline_call was called.\n");   
   }  
   void normal_call();  
   Example2() {};  
};  
```  
  
```cpp  
// example2.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp  
#include "example2.h"  
  
void Example2::normal_call() {  
   printf("normal_call was called.\n");   
   inline_call();   
}  
```  
  
```cpp  
// zcinline2.cpp  
// Compile by using: cl /W4 /EHsc /O2 zcinline2.cpp example2.cpp  
#include "example2.h"  
  
void main() {  
   Example2 example2;  
   example2.inline_call(); // normal call when definition unavailable  
}  
```  
  
 Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir `/Zc:inline` e, em seguida, escolha **Okey**.  
  
## <a name="see-also"></a>Consulte também  
 [/ZC (conformidade)](../../build/reference/zc-conformance.md)