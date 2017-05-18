---
title: Aviso LNK4049 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4049
dev_langs:
- C++
helpviewer_keywords:
- LNK4049
ms.assetid: 5fd5fb24-c860-4149-a557-0ac26a65d97c
caps.latest.revision: 19
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 337a980e74397459e8d3930ce3992a2e55eb6173
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4049"></a>Aviso LNK4049 (Ferramentas de Vinculador)
definida localmente o símbolo 'symbol' importado  
  
 O símbolo foi tanto exportado do e importado para o programa.  
  
 Esse aviso é gerado pelo vinculador quando você declarar um símbolo usando o `__declspec(dllexport)` classe de armazenamento de atributos no arquivo de um objeto e fazer referência a ele usando o `__declspec(dllimport)` atributo em outro.  
  
 Aviso LNK4049 é uma versão mais geral de [vinculador ferramentas aviso LNK4217](../../error-messages/tool-errors/linker-tools-warning-lnk4217.md). O vinculador gera o aviso LNK4049 quando não é possível determinar de qual função o símbolo importado foi referenciado.  
  
 Os casos comuns onde LNK4049 é gerada, em vez de LNK4217 são:  
  
-   Executar a vinculação incremental usando o [/incremental](../../build/reference/incremental-link-incrementally.md) opção.  
  
-   Executar a otimização de todo o programa usando o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção.  
  
 Para resolver LNK4049, tente um destes procedimentos:  
  
-   Remover o `__declspec(dllimport)` nome de declaração da declaração de encaminhamento do símbolo que disparou LNK4049. Você pode procurar por símbolos em uma imagem binária usando o **DUMPBIN** utilitário. O **DUMPBIN/símbolos** opção exibe a tabela de símbolos COFF da imagem. Para obter mais informações sobre o **DUMPBIN** utilitário, consulte [referência de DUMPBIN](../../build/reference/dumpbin-reference.md).  
  
-   Desabilite temporariamente a vinculação incremental e a otimização de programa total. Recompilar o aplicativo irá gerar aviso LNK4217, que incluirá o nome da função da qual o símbolo importado foi referenciado. Remover o `__declspec(dllimport)` declaração do símbolo importado e habilitar vinculação incremental ou otimização de todo o programa conforme necessário.  
  
 Embora o código gerado final irão se comportar corretamente, o código gerado para chamar a função importada é menos eficiente do que chamar a função diretamente. Esse aviso não aparecerá quando você compila com a opção [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 Para obter mais informações sobre como importar e exportar declarações de dados, consulte [dllexport, dllimport](../../cpp/dllexport-dllimport.md).  
  
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
