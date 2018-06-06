---
title: /CLRUNMANAGEDCODECHECK (Adicionar SupressUnmanagedCodeSecurityAttribute) | Microsoft Docs
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
ms.openlocfilehash: 9d0a70ea74851d3a10f9d46b8289098d6fb3fe22
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34705368"
---
# <a name="clrunmanagedcodecheck-add-supressunmanagedcodesecurityattribute"></a>/CLRUNMANAGEDCODECHECK (Adicionar SupressUnmanagedCodeSecurityAttribute)

**/CLRUNMANAGEDCODECHECK** Especifica se o vinculador aplicará <xref:System.Security.SuppressUnmanagedCodeSecurityAttribute> para geradas pelo vinculador `PInvoke` chamadas de código gerenciado nas DLLs nativas.

## <a name="syntax"></a>Sintaxe

> **/CLRUNMANAGEDCODECHECK**[**: NENHUM**]

## <a name="remarks"></a>Comentários

Por padrão, o vinculador aplica o **SuppressUnmanagedCodeSecurityAttribute** para geradas pelo vinculador `PInvoke` chamadas. Quando **/CLRUNMANAGEDCODECHECK** está em vigor, **SuppressUnmanagedCodeSecurityAttribute** não é aplicada.

O vinculador apenas adiciona o atributo para objetos que são compilados com **/clr** ou **/clr: pure**. No entanto, o **/clr: pure** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Um `PInvoke` chamada é gerada pelo vinculador quando o vinculador não é possível encontrar um símbolo gerenciado para atender a uma referência de um chamador gerenciado, mas pode encontrar um símbolo nativo para atender a essa referência. Para obter mais informações sobre `PInvoke`, consulte [chamando funções nativas do código gerenciado](../../dotnet/calling-native-functions-from-managed-code.md).

Observe que, se você usar <xref:System.Security.AllowPartiallyTrustedCallersAttribute> em seu código, você deve definir explicitamente **/CLRUNMANAGEDCODECHECK**. É possível vulnerabilidade de segurança se uma imagem contém atributos de SuppressUnmanagedCodeSecurity e AllowPartiallyTrustedCallers.

Consulte [diretrizes de codificação segura para código não gerenciado](/dotnet/framework/security/secure-coding-guidelines-for-unmanaged-code) para obter mais informações sobre as implicações de usar **SuppressUnmanagedCodeSecurityAttribute**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o **propriedades de configuração** nó.

1. Expanda o **vinculador** nó.

1. Selecione o **avançado** página de propriedades.

1. Modificar o **verificar código não gerenciado do CLR** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRUnmanagedCodeCheck%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
