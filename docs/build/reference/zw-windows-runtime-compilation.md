---
title: /ZW (Compilação de Tempo de Execução do Windows)
ms.date: 04/08/2019
f1_keywords:
- VC.Project.VCCLCompilerTool.CompileAsWinRT
- /zw
helpviewer_keywords:
- /ZW
- -ZW compiler option
- /ZW compiler option
- -ZW
- Windows Runtime compiler option
ms.assetid: 0fe362b0-9526-498b-96e0-00d7a965a248
ms.openlocfilehash: 0808f66c4d4c4e99b3038ea18a1f71f4ebaca89a
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65446170"
---
# <a name="zw-windows-runtime-compilation"></a>/ZW (Compilação de Tempo de Execução do Windows)

Compila o código para dar suporte a Microsoft-fonte C++ extensões de componentes C++/CX para a criação de aplicativos da plataforma Universal do Windows (UWP).

Quando você usa **/ZW** para compilar, sempre especifique **/EHsc** também.

## <a name="syntax"></a>Sintaxe

```cpp
/ZW /EHsc
/ZW:nostdlib /EHsc
```

## <a name="arguments"></a>Arguments

**nostdlib**<br/>
Indica que Platform.winmd, Windows.Foundation.winmd e outros arquivos padrão de metadados do Windows (.winmd) não são incluídos automaticamente na compilação. Em vez disso, você deve usar o [/FU (nome forçado #using arquivo)](fu-name-forced-hash-using-file.md) opção de compilador para especificar explicitamente os arquivos de metadados do Windows.

## <a name="remarks"></a>Comentários

Quando você especifica o **/ZW** opção, o compilador dá suporte a esses recursos:

- Os arquivos de metadados, namespaces, tipos de dados e funções que seu aplicativo requer para executar no tempo de execução do Windows.

- Automático-contagem de referência de objetos de tempo de execução do Windows e o descarte automático de um objeto quando sua contagem de referência chega a zero.

Como o vinculador incremental não oferece suporte a metadados do Windows incluídos em arquivos. obj usando a **/ZW** opção preteridas [/Gm (habilitar recompilação mínima)](gm-enable-minimal-rebuild.md) opção é incompatível com **/ZW**.

Para obter mais informações, consulte [referência de linguagem do Visual C++](../../cppcx/visual-c-language-reference-c-cx.md).

## <a name="requirements"></a>Requisitos

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
