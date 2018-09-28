---
title: /CLRUNMANAGEDCODECHECK (Adicionar SuppressUnmanagedCodeSecurityAttribute) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /CLRUNMANAGEDCODECHECK
dev_langs:
- C++
helpviewer_keywords:
- -CLRUNMANAGEDCODECHECK linker option
- /CLRUNMANAGEDCODECHECK linker option
ms.assetid: 73abc426-dab0-45e2-be85-0f9a14206cc2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 679adc527cc70056e1292eb7e639499bd814bca6
ms.sourcegitcommit: 7838764e09819822a105accf5d773b2e37ffa0ae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2018
ms.locfileid: "47429755"
---
# <a name="clrunmanagedcodecheck-add-suppressunmanagedcodesecurityattribute"></a>/CLRUNMANAGEDCODECHECK (Adicionar SuppressUnmanagedCodeSecurityAttribute)

**/CLRUNMANAGEDCODECHECK** Especifica se o vinculador aplicará <xref:System.Security.SuppressUnmanagedCodeSecurityAttribute> como gerada pelo vinculador `PInvoke` chamadas de código gerenciado nas DLLs nativas.

## <a name="syntax"></a>Sintaxe

> **/CLRUNMANAGEDCODECHECK**[**: NENHUMA**]

## <a name="remarks"></a>Comentários

Por padrão, o vinculador aplica-se a **SuppressUnmanagedCodeSecurityAttribute** como gerada pelo vinculador `PInvoke` chamadas. Quando **/CLRUNMANAGEDCODECHECK** está em vigor, **SuppressUnmanagedCodeSecurityAttribute** não será aplicado.

O vinculador só adiciona o atributo para objetos que são compilados com **/clr** ou **/clr: pure**. No entanto, o **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Um `PInvoke` chamada será gerada pelo vinculador quando o vinculador não é possível encontrar um símbolo gerenciado para satisfazer uma referência de um chamador gerenciado, mas pode encontrar um símbolo de nativo para atender a essa referência. Para obter mais informações sobre `PInvoke`, consulte [Calling Native Functions from Managed Code](../../dotnet/calling-native-functions-from-managed-code.md).

Observe que, se você usar <xref:System.Security.AllowPartiallyTrustedCallersAttribute> em seu código, você deve definir explicitamente **/CLRUNMANAGEDCODECHECK**. É possível vulnerabilidade de segurança se uma imagem contiver atributos SuppressUnmanagedCodeSecurity tanto o AllowPartiallyTrustedCallers.

Ver [diretrizes de codificação segura para código não gerenciado](/dotnet/framework/security/secure-coding-guidelines-for-unmanaged-code) para obter mais informações sobre as implicações do uso **SuppressUnmanagedCodeSecurityAttribute**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **avançado** página de propriedades.

1. Modificar a **verificar código não gerenciado do CLR** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRUnmanagedCodeCheck%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
