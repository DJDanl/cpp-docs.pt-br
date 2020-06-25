---
title: /MANIFESTUAC (insere informações UAC no manifesto)
ms.date: 06/12/2020
f1_keywords:
- VC.Project.VCLinkerTool.UACUIAccess
- VC.Project.VCLinkerTool.UACExecutionLevel
- VC.Project.VCLinkerTool.EnableUAC
helpviewer_keywords:
- /MANIFESTUAC linker option
- MANIFESTUAC linker option
- -MANIFESTUAC linker option
ms.assetid: 2d243c39-fa13-493c-b56f-d0d972a1603a
ms.openlocfilehash: 96719c6f6f5359afb03b967524b1f65db6dc664a
ms.sourcegitcommit: 8645408c7929558b8162f781776d0908d790a41c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/24/2020
ms.locfileid: "85334931"
---
# <a name="manifestuac-embeds-uac-information-in-manifest"></a>/MANIFESTUAC (insere informações UAC no manifesto)

Especifica se as informações do UAC (Controle de Conta de Usuário) estão inseridas no manifesto do programa.

## <a name="syntax"></a>Sintaxe

> **`/MANIFESTUAC`**\
> **`/MANIFESTUAC:NO`**\
> **`/MANIFESTUAC:`**_`level`_\
> **`/MANIFESTUAC:`**_`uiAccess`_\
> **`/MANIFESTUAC:`**_`fragment`_

### <a name="parameters"></a>Parâmetros

**`NO`**<br/>
O vinculador não incorpora informações do UAC no manifesto do programa.

*`level`*<br/>
**`level=`** seguido por um dos **`'asInvoker'`** , **`'highestAvailable'`** ou **`'requireAdministrator'`** . O padrão é **`'asInvoker'`** . Para obter mais informações, consulte a seção [comentários](#remarks) .

*`uiAccess`*<br/>
**`uiAccess='true'`** Se você quiser que o aplicativo ignore os níveis de proteção da interface do usuário e a entrada da unidade para janelas de permissões mais altas na área de trabalho; caso contrário, **`uiAccess='false'`** . O padrão é **`uiAccess='false'`** . Defina este argumento como **`uiAccess='true'`** somente para aplicativos de acessibilidade da interface do usuário.

*`fragment`*<br/>
Uma cadeia de caracteres que contém os *`level`* *`uiAccess`* valores e. Opcionalmente, pode ser colocado entre aspas duplas. Para obter mais informações, consulte a seção [comentários](#remarks) .

## <a name="remarks"></a>Comentários

Se você especificar várias **`/MANIFESTUAC`** Opções na linha de comando, a última digitada terá precedência.

As opções para o **`/MANIFESTUAC:`** _`level`_ são as seguintes:

- **`level='asInvoker'`**: O aplicativo é executado no mesmo nível de permissão que o processo que o iniciou. Você pode elevar o aplicativo a um nível de permissão mais alto selecionando **Executar como administrador**.

- **`level='highestAvailable'`**: O aplicativo é executado no nível de permissão mais alto que ele pode. Se o usuário que inicia o aplicativo for membro do grupo Administradores, essa opção será a mesma do **`level='requireAdministrator'`** . Se o nível de permissão mais alto disponível for maior do que o nível do processo de abertura, o sistema solicitará as credenciais.

- **`level='requireAdministrator'`**: O aplicativo é executado usando permissões de administrador. O usuário que inicia o aplicativo deve ser membro do grupo Administradores. Se o processo de abertura não estiver sendo executado com permissões administrativas, o sistema solicitará as credenciais.

Você pode especificar os *`level`* valores e *`uiAccess`* em uma etapa usando a **`/MANIFESTUAC:`** _`fragment`_ opção. O fragmento deve estar no seguinte formato:

> **`/MANIFESTUAC:`** \[ **`"`** ] **`level=`** { **`'asInvoker'`** | **`'highestAvailable'`** | **`'requireAdministrator'`** } **`uiAccess=`** { **`'true'`** | **`'false'`** } \[ **`"`** ]

Por exemplo:

**`/MANIFESTUAC:"level='highestAvailable' uiAccess='true'"`**

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de Propriedade do arquivo de manifesto do**vinculador**de propriedades de configuração  >  **Manifest File** .

1. Modifique as propriedades **habilitar UAC (controle de conta de usuário)**, **nível de execução UAC**e **proteção de IU bypass do UAC** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableUAC%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACExecutionLevel%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.UACUIAccess%2A>.

## <a name="see-also"></a>Veja também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
