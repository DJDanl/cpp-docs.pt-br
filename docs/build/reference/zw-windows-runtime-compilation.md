---
title: /ZW (Compilação de Tempo de Execução do Windows)
ms.date: 11/04/2016
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
ms.openlocfilehash: 944d66de3c029d9731a225281b4e592c477806e9
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417977"
---
# <a name="zw-windows-runtime-compilation"></a>/ZW (Compilação de Tempo de Execução do Windows)

Compila o código para dar suporte a extensões de componentes do Visual C++ C + +-fonte c++ /CX para a criação de aplicativos da plataforma Universal do Windows (UWP).

Quando você usa **/ZW** para compilar, sempre especifique **/EHsc** também.

## <a name="syntax"></a>Sintaxe

```cpp
/ZW /EHsc
/ZW:nostdlib /EHsc
```

## <a name="arguments"></a>Arguments

**nostdlib**<br/>
Indica que Platform.winmd, Windows.Foundation.winmd e outros arquivos padrão de metadados do Windows (.winmd) não são incluídos automaticamente na compilação. Em vez disso, você deve usar o [/FU (nome forçado #using arquivo)](../../build/reference/fu-name-forced-hash-using-file.md) opção de compilador para especificar explicitamente os arquivos de metadados do Windows.

## <a name="remarks"></a>Comentários

Quando você especifica o **/ZW** opção, o compilador dá suporte a esses recursos:

- Os arquivos de metadados, namespaces, tipos de dados e funções que seu aplicativo requer para executar no tempo de execução do Windows.

- Automático-contagem de referência de objetos de tempo de execução do Windows e o descarte automático de um objeto quando sua contagem de referência chega a zero.

Como o vinculador incremental não oferece suporte a metadados do Windows incluídos em arquivos. obj usando a **/ZW** opção, o [/Gm (habilitar recompilação mínima)](../../build/reference/gm-enable-minimal-rebuild.md) opção é incompatível com **/ZW** .

Para obter mais informações, consulte [referência de linguagem do Visual C++](../../cppcx/visual-c-language-reference-c-cx.md).

## <a name="requirements"></a>Requisitos

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
