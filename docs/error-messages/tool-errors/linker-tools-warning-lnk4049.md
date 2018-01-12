---
title: Aviso LNK4049 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4049
dev_langs: C++
helpviewer_keywords: LNK4049
ms.assetid: 5fd5fb24-c860-4149-a557-0ac26a65d97c
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f44634bd99e485e444ffe9cee7747f31374becf4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4049"></a>Aviso LNK4049 (Ferramentas de Vinculador)
definidos localmente o símbolo 'symbol' importado  
  
 O símbolo foi tanto exportado do e importado para o programa.  
  
 Esse aviso é gerado pelo vinculador quando você declara um símbolo usando o `__declspec(dllexport)` classe de armazenamento de atributos no arquivo de um objeto e fazer referência a ele usando o `__declspec(dllimport)` atributo em outro.  
  
 Aviso LNK4049 é uma versão mais geral de [LNK4217 de aviso de ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-warning-lnk4217.md). O vinculador gera aviso LNK4049 quando não é possível determinar de qual função o símbolo importado foi referenciado.  
  
 Os casos comuns onde LNK4049 é gerado em vez de LNK4217 são:  
  
-   Executar o vínculo incremental usando o [/incremental](../../build/reference/incremental-link-incrementally.md) opção.  
  
-   Executar a otimização de programa inteiro usando o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção.  
  
 Para resolver LNK4049, tente um destes procedimentos:  
  
-   Remover o `__declspec(dllimport)` nome de declaração na declaração de encaminhamento do símbolo que disparou LNK4049. Você pode procurar símbolos em uma imagem binária usando o **DUMPBIN** utilitário. O **DUMPBIN/símbolos** opção exibe a tabela de símbolos COFF da imagem. Para obter mais informações sobre o **DUMPBIN** utilitário, consulte [referência de DUMPBIN](../../build/reference/dumpbin-reference.md).  
  
-   Desabilite temporariamente o vínculo incremental e otimização de programa inteiro. Recompilar o aplicativo irá gerar aviso LNK4217, que incluirá o nome da função da qual o símbolo importado foi referenciado. Remover o `__declspec(dllimport)` declaração do símbolo importado e habilitar a vinculação incremental ou otimização de programa inteiro conforme necessário.  
  
 Embora o código gerado final irão se comportar corretamente, o código gerado para chamar a função importada é menos eficiente do que chamar a função diretamente. Esse aviso não aparecerá quando você compila usando a opção [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 Para obter mais informações sobre importar e exportar dados de declarações, consulte [dllexport, dllimport](../../cpp/dllexport-dllimport.md).  
  
## <a name="example"></a>Exemplo  
 Vincular os dois módulos a seguir irá gerar LNK4049. O primeiro módulo gera um arquivo de objeto que contém uma única função exportada.  
  
```  
// LNK4049a.cpp  
// compile with: /c  
  
__declspec(dllexport) int func()   
{  
   return 3;  
}  
```  
  
## <a name="example"></a>Exemplo  
 O segundo módulo gera um arquivo de objeto que contém uma declaração de encaminhamento para a função exportada no primeiro módulo, juntamente com uma chamada para essa função dentro de `main` função. Vincular este módulo com o primeiro módulo irá gerar LNK4049. Removendo o `__declspec(dllimport)` declaração resolverá o aviso.  
  
```  
// LNK4049b.cpp  
// compile with: /link /WX /LTCG LNK4049a.obj  
// LNK4049 expected  
  
__declspec(dllimport) int func();  
// try the following line instead  
// int func();  
  
int main()  
{  
   return func();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Aviso LNK4217 ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-warning-lnk4217.md)   
 [dllexport, dllimport](../../cpp/dllexport-dllimport.md)