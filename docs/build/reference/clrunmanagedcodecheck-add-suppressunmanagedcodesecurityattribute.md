---
title: /CLRUNMANAGEDCODECHECK (Remover SuppressUnmanagedCodeSecurityAttribute)
ms.date: 05/16/2019
ms.topic: reference
f1_keywords:
- /CLRUNMANAGEDCODECHECK
helpviewer_keywords:
- -CLRUNMANAGEDCODECHECK linker option
- /CLRUNMANAGEDCODECHECK linker option
ms.assetid: 73abc426-dab0-45e2-be85-0f9a14206cc2
author: corob-msft
ms.author: corob
ms.openlocfilehash: ecc560673a8e98752289ef0e0f89d3abfc1938e4
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837235"
---
# <a name="clrunmanagedcodecheck-remove-suppressunmanagedcodesecurityattribute"></a>/CLRUNMANAGEDCODECHECK (Remover SuppressUnmanagedCodeSecurityAttribute)

**/CLRUNMANAGEDCODECHECK** especifica que o vinculador não aplica <xref:System.Security.SuppressUnmanagedCodeSecurityAttribute> às chamadas `PInvoke` geradas pelo vinculador do código gerenciado em DLLs nativas.

## <a name="syntax"></a>Sintaxe

> **/CLRUNMANAGEDCODECHECK**[**:NO**]

## <a name="remarks"></a>Comentários

Por padrão, o vinculador aplica o **SuppressUnmanagedCodeSecurityAttribute** às chamadas `PInvoke` geradas pelo vinculador. Quando **/CLRUNMANAGEDCODECHECK** está em vigor, **SuppressUnmanagedCodeSecurityAttribute** é removido. Para aplicar explicitamente o **SuppressUnmanagedCodeSecurityAttribute** às chamadas `PInvoke` geradas pelo vinculador, use **/CLRUNMANAGEDCODECHECK:NO**.

O vinculador só adiciona o atributo a objetos que são compilados usando **/clr** ou **/clr:pure**. No entanto, a opção do compilador **/clr:pure** foi preterida no Visual Studio 2015 e está sem suporte no Visual Studio 2017 e posterior.

Uma chamada `PInvoke` é gerada pelo vinculador quando ele não pode encontrar um símbolo gerenciado para atender a uma referência de um chamador gerenciado, mas pode encontrar um símbolo nativo para atender a essa referência. Para obter mais informações sobre `PInvoke`, confira [Como chamar funções nativas do código gerenciado](../../dotnet/calling-native-functions-from-managed-code.md).

Observe que, se você usar <xref:System.Security.AllowPartiallyTrustedCallersAttribute> no código, você deverá definir explicitamente **/CLRUNMANAGEDCODECHECK** para remover o atributo **SuppressUnmanagedCodeSecurity**. É uma possível vulnerabilidade de segurança se uma imagem contém os atributos **SuppressUnmanagedCodeSecurity** e **AllowPartiallyTrustedCallers**.

Confira [Diretrizes de codificação segura para código não gerenciado](/dotnet/framework/security/secure-coding-guidelines-for-unmanaged-code) para obter mais informações sobre as implicações do uso de **SuppressUnmanagedCodeSecurityAttribute**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o nó **Vinculador**.

1. Selecione a página de propriedades **Avançado**.

1. Modifique a propriedade **Verificação de Código não Gerenciado CLR**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRUnmanagedCodeCheck%2A>.

## <a name="see-also"></a>Consulte também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
