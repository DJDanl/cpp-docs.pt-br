---
title: /ENTRY (símbolo do ponto de entrada)
ms.date: 11/04/2016
f1_keywords:
- /entry
- VC.Project.VCLinkerTool.EntryPointSymbol
helpviewer_keywords:
- starting address
- -ENTRY linker option
- /ENTRY linker option
- ENTRY linker option
ms.assetid: 26c62ba2-4f52-4882-a7bd-7046a0abf445
ms.openlocfilehash: 80833980b64e8fdd2a2f57b2dc40eb21c784b6f9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232697"
---
# <a name="entry-entry-point-symbol"></a>/ENTRY (símbolo do ponto de entrada)

```
/ENTRY:function
```

## <a name="arguments"></a>Argumentos

*função*<br/>
Uma função que especifica um endereço inicial definido pelo usuário para um arquivo. exe ou DLL.

## <a name="remarks"></a>Comentários

A opção/ENTRY especifica uma função de ponto de entrada como o endereço inicial de um arquivo. exe ou DLL.

A função deve ser definida para usar a **`__stdcall`** Convenção de chamada. Os parâmetros e o valor de retorno dependem de se o programa for um aplicativo de console, um aplicativo do Windows ou uma DLL. É recomendável permitir que o vinculador defina o ponto de entrada para que a biblioteca de tempo de execução do C seja inicializada corretamente e que os construtores do C++ para objetos estáticos sejam executados.

Por padrão, o endereço inicial é um nome de função da biblioteca de tempo de execução do C. O vinculador seleciona-o de acordo com os atributos do programa, conforme mostrado na tabela a seguir.

|Nome da função|Padrão para|
|-------------------|-----------------|
|**mainCRTStartup** (ou **wmainCRTStartup**)|Um aplicativo que usa/SUBSYSTEM: CONSOLE; chamadas `main` (ou `wmain` )|
|**WinMainCRTStartup** (ou **wWinMainCRTStartup**)|Um aplicativo que usa/SUBSYSTEM:**Windows**; chamadas `WinMain` (ou `wWinMain` ), que devem ser definidas para usar**`__stdcall`**|
|**_DllMainCRTStartup**|UMA DLL; chama `DllMain` se ele existe, que deve ser definido para usar**`__stdcall`**|

Se a opção [/dll](dll-build-a-dll.md) ou [/Subsystem](subsystem-specify-subsystem.md) não for especificada, o vinculador selecionará um subsistema e um ponto de entrada dependendo de se `main` ou `WinMain` está definido.

As funções `main` , `WinMain` e `DllMain` são as três formas do ponto de entrada definido pelo usuário.

Ao criar uma imagem gerenciada, a função especificada para/ENTRY deve ter uma assinatura de (LPVOID *var1*, DWORD *var2*, LPVOID *var3*).

Para obter informações sobre como definir seu próprio `DllMain` ponto de entrada, consulte [DLLs e Visual C++ comportamento da biblioteca de tempo de execução](../run-time-library-behavior.md) .

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades **avançado** .

1. Modifique a propriedade de **ponto de entrada** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EntryPointSymbol%2A>.

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
