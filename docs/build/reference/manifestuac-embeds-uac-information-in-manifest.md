---
title: -MANIFESTUAC (insere informações UAC no manifesto) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.UACUIAccess
- VC.Project.VCLinkerTool.UACExecutionLevel
- VC.Project.VCLinkerTool.EnableUAC
dev_langs:
- C++
helpviewer_keywords:
- /MANIFESTUAC linker option
- MANIFESTUAC linker option
- -MANIFESTUAC linker option
ms.assetid: 2d243c39-fa13-493c-b56f-d0d972a1603a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bdfd872b43fbabdb14457ca54e6c4dfbe039313f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377268"
---
# <a name="manifestuac-embeds-uac-information-in-manifest"></a>/MANIFESTUAC (insere informações UAC no manifesto)
Especifica se as informações do UAC (Controle de Conta de Usuário) estão inseridas no manifesto do programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/MANIFESTUAC  
/MANIFESTUAC:NO  
/MANIFESTUAC:fragment  
/MANIFESTUAC:level=_level  
/MANIFESTUAC:uiAccess=_uiAccess  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fragment`  
 Uma cadeia de caracteres que contém o `level` e `uiAccess` valores. Para obter mais informações, consulte a seção comentários mais adiante neste tópico.  
  
 `_level`  
 Um dos *asInvoker*, *highestAvailable*, ou *requireAdministrator*. O padrão é asInvoker. Para obter mais informações, consulte a seção comentários mais adiante neste tópico.  
  
 `_uiAccess`  
 `true` Se você deseja que o aplicativo para ignorar os níveis de proteção de interface do usuário e a unidade de entrada para windows de permissão mais alta na área de trabalho; Caso contrário, `false`. Assume o padrão de `false`. Definido como `true` somente para aplicativos de acessibilidade de interface do usuário.  
  
## <a name="remarks"></a>Comentários  
 Se você especificar várias opções de /MANIFESTUAC na linha de comando, o último deles inserido terá precedência.  
  
 As opções para /MANIFESTUAC:level são da seguinte maneira:  
  
-   `asInvoker`: O aplicativo será executado com as mesmas permissões que o processo que ele foi iniciado. O aplicativo pode ser elevado para um nível mais alto de permissão selecionando **executar como administrador**.  
  
-   highestAvailable: O aplicativo será executado com o maior nível de permissão que pode. Se o usuário que inicia o aplicativo for um membro do grupo Administradores, essa opção é o mesmo que requireAdministrator. Se o nível de permissão mais alto for maior do que o nível de processo de abertura, o sistema solicitará credenciais.  
  
-   requireAdministrator: O aplicativo será executado com permissões de administrador. O usuário que inicia o aplicativo deve ser um membro do grupo Administradores. Se o processo de abertura não está em execução com permissões administrativas, o sistema solicitará credenciais.  
  
 Você pode especificar os valores nível e uiAccess em uma etapa usando a opção /MANIFESTUAC:fragment. O fragmento deve estar no seguinte formato:  
  
```  
"level=[ asInvoker | highestAvailable | requireAdministrator ] uiAccess=[ true | false ]"  
```  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **o arquivo de manifesto** página de propriedades.  
  
5.  Modificar o **controle de conta de usuário (UAC) habilitar**, **nível de execução UAC**, e **proteção de interface do usuário de desvio de UAC** propriedades.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableUAC%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACExecutionLevel%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACUIAccess%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)