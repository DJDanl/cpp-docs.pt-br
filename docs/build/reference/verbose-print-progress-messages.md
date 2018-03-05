---
title: -VERBOSE (Imprimir mensagens de progresso) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /verbose
- VC.Project.VCLinkerTool.ShowProgress
dev_langs:
- C++
helpviewer_keywords:
- -VERBOSE linker option
- linking [C++], session progress information
- Print Progress Messages linker option
- linker [C++], output dependency information
- /VERBOSE linker option
- dependencies [C++], dependency information in linker output
- VERBOSE linker option
ms.assetid: 9c347d98-4c37-4724-a39e-0983934693ab
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 76ead441a8dc7ec65a6966371b83d42c47c897c9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="verbose-print-progress-messages"></a>/VERBOSE (imprimir mensagens de progresso)
```  
/VERBOSE[:{ICF|INCR|LIB|REF|SAFESEH|UNUSEDLIBS}]  
```  
  
## <a name="remarks"></a>Comentários  
 O vinculador envia informações sobre o andamento da sessão de vinculação para o **saída** janela. Na linha de comando, as informações são enviadas para a saída padrão e podem ser redirecionadas para um arquivo.  
  
|Opção|Descrição|  
|------------|-----------------|  
|/VERBOSE|Exibe detalhes sobre o processo de vinculação.|  
|/VERBOSE: ICF|Exibir informações sobre a atividade de vinculador resultante do uso de [/OPT: ICF](../../build/reference/opt-optimizations.md).|  
|/VERBOSE: INCR|Exibe informações sobre o processo de vínculo incremental.|  
|/VERBOSE: LIB|Exibe mensagens de progresso indicando apenas as bibliotecas pesquisadas.<br /><br /> As informações exibidas incluem o processo de pesquisa de biblioteca e lista cada nome de biblioteca e objeto (com o caminho completo), o símbolo que está sendo resolvido a partir de biblioteca e uma lista de objetos que fazem referência o símbolo.|  
|/VERBOSE: REF|Exibe informações sobre a atividade de vinculador resultante do uso de [/OPT: REF](../../build/reference/opt-optimizations.md).|  
|/VERBOSE: SAFESEH|Exibe informações sobre os módulos que não são compatíveis com a exceção de segurança tratamento quando [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md) não for especificado.|  
|/VERBOSE: UNUSEDLIBS|Exibe informações sobre quaisquer arquivos de biblioteca que não são utilizadas quando a imagem é criada.|  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **vinculador** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Adicione a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ShowProgress%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)