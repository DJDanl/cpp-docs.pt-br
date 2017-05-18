---
title: "PRJ0003 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0003
dev_langs:
- C++
helpviewer_keywords:
- PRJ0003
ms.assetid: fc5a84bb-c6d3-41d6-8dd6-475455820778
caps.latest.revision: 7
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
ms.openlocfilehash: aac7a37a94013a1acad8ee866d9ac7ce28fda94c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0003"></a>Erro de Build PRJ0003 no Projeto
Erro ao gerar a 'linha de comando '.  
  
 Um comando, ***linha de comando***, que foi formado de entrada no **páginas de propriedade** caixa de diálogo, retornada um código de erro, mas nenhuma informação será exibida na janela de saída.  
  
 Possíveis motivos para esse erro:  
  
-   Seu projeto depende do servidor ATL. Começando com [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], ATL Server não está mais incluída como parte do Visual Studio, mas foi lançado como um projeto de código-fonte compartilhado no CodePlex. Para baixar o código-fonte ATL Server e ferramentas, vá para [http://go.microsoft.com/fwlink/?LinkID=81979](http://go.microsoft.com/fwlink/?LinkID=81979).  
  
-   Recursos insuficientes do sistema. Feche alguns aplicativos para resolver o problema.  
  
-   Privilégios de segurança insuficientes. Verifique se você tem privilégios suficientes.  
  
-   Os executáveis caminhos especificados na [diretórios VC + +](http://msdn.microsoft.com/en-us/e027448b-c811-4c3d-8531-4325ad3f6e02) não inclua o caminho para a ferramenta que você está tentando executar.  
  
-   Para projetos de makefile estiver faltando um comando para executar **linha de comando de compilação** ou **reconstruir a linha de comando**.  
  
## <a name="see-also"></a>Consulte também  
 [Erros de compilação e avisos projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)
