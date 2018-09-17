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
ms.openlocfilehash: 1b3997f8beb414992464c51ca1c1fd944145c43d
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45715137"
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

### <a name="parameters"></a>Parâmetros

*Fragmento*<br/>
Uma cadeia de caracteres que contém o `level` e `uiAccess` valores. Para obter mais informações, consulte a seção comentários mais adiante neste tópico.

*nível*<br/>
Um dos *asInvoker*, *highestAvailable*, ou *requireAdministrator*. O padrão é asInvoker. Para obter mais informações, consulte a seção comentários mais adiante neste tópico.

*_uiAccess*<br/>
`true` Se você deseja que o aplicativo para ignorar os níveis de proteção de interface do usuário e a unidade de entrada para janelas de permissão superior na área de trabalho; Caso contrário, `false`. Assume o padrão de `false`. Definido como `true` somente para aplicativos de acessibilidade de interface do usuário.

## <a name="remarks"></a>Comentários

Se você especificar várias opções de /MANIFESTUAC na linha de comando, o último inserida terá precedência.

As opções para /MANIFESTUAC:level são da seguinte maneira:

- `asInvoker`: O aplicativo será executado com as mesmas permissões que o processo que o iniciou. O aplicativo pode ser elevado para um nível mais alto de permissão, selecionando **executar como administrador**.

- highestAvailable: O aplicativo será executado com o maior nível de permissão que ele pode. Se o usuário que inicia o aplicativo for um membro do grupo Administradores, essa opção é o mesmo que requireAdministrator. Se o nível mais alto de permissões disponíveis for maior do que o nível de processo de abertura, o sistema solicitará as credenciais.

- requireAdministrator: O aplicativo será executado com permissões de administrador. O usuário que inicia o aplicativo deve ser um membro do grupo Administradores. Se o processo de abertura não está em execução com permissões administrativas, o sistema solicitará as credenciais.

Você pode especificar os valores de nível e uiAccess em uma etapa usando a opção /MANIFESTUAC:fragment. O fragmento deve ser da seguinte forma:

```
"level=[ asInvoker | highestAvailable | requireAdministrator ] uiAccess=[ true | false ]"
```

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **o arquivo de manifesto** página de propriedades.

1. Modificar a **controle de conta de usuário (UAC) permitem**, **nível de execução UAC**, e **proteção de interface do usuário de desvio de UAC** propriedades.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableUAC%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACExecutionLevel%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACUIAccess%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)