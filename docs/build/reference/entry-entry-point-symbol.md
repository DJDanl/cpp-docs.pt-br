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
ms.openlocfilehash: 0f3604ef75ce10928463c088e423615886555eda
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293206"
---
# <a name="entry-entry-point-symbol"></a>/ENTRY (símbolo do ponto de entrada)

```
/ENTRY:function
```

## <a name="arguments"></a>Arguments

*function*<br/>
Endereço de uma função que especifica um iniciado definidas pelo usuário para um arquivo .exe ou DLL.

## <a name="remarks"></a>Comentários

A opção /ENTRY Especifica uma função de ponto de entrada como o endereço inicial para um arquivo .exe ou DLL.

A função deve ser definida para usar o `__stdcall` convenção de chamada. O valor de retorno e parâmetros dependem se o programa é um aplicativo de console, um aplicativo do windows ou uma DLL. É recomendável que você permita que o vinculador defina o ponto de entrada para que a biblioteca de tempo de execução C é inicializada corretamente, e construtores de C++ para objetos estáticos são executados.

Por padrão, o endereço inicial é um nome de função da biblioteca em tempo de execução C. O vinculador seleciona acordo com os atributos do programa, como mostrado na tabela a seguir.

|Nome da função|Padrão para|
|-------------------|-----------------|
|**mainCRTStartup** (ou **wmainCRTStartup**)|Um aplicativo que usa /Subsystem: console; chamadas `main` (ou `wmain`)|
|**WinMainCRTStartup** (ou **wWinMainCRTStartup**)|Um aplicativo que usa /SUBSYSTEM:**WINDOWS**; chamadas `WinMain` (ou `wWinMain`), que deve ser definido para usar `__stdcall`|
|**_DllMainCRTStartup**|UMA DLL; chamadas `DllMain` se ele existir, que deve ser definido para usar `__stdcall`|

Se o [/DLL](dll-build-a-dll.md) ou [/SUBSYSTEM](subsystem-specify-subsystem.md) opção não for especificada, o vinculador seleciona um ponto de entrada e o subsistema, dependendo se `main` ou `WinMain` é definido.

As funções `main`, `WinMain`, e `DllMain` são as três formas de ponto de entrada definido pelo usuário.

Ao criar uma imagem gerenciada, a função especificada para /ENTRY deve ter uma assinatura de (LPVOID *var1*, DWORD *var2*, LPVOID *var3*).

Para obter informações sobre como definir seus próprios `DllMain` ponto de entrada, consulte [DLLs e Visual C++ comportamento da biblioteca em tempo de execução](../run-time-library-behavior.md) .

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **ponto de entrada** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EntryPointSymbol%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
