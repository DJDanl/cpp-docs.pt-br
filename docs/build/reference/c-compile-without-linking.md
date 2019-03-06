---
title: /c (compilar sem vinculação)
ms.date: 11/04/2016
f1_keywords:
- /c
helpviewer_keywords:
- suppress link
- cl.exe compiler, compiling without linking
- -c compiler option [C++]
- c compiler option [C++]
- /c compiler option [C++]
ms.assetid: 8017fc3d-e5dd-4668-a1f7-3120daa95d20
ms.openlocfilehash: cdce86f9ba74b2541529d922c580d6393a93f775
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57416452"
---
# <a name="c-compile-without-linking"></a>/c (compilar sem vinculação)

Impede que a chamada automática para o LINK.

## <a name="syntax"></a>Sintaxe

```
/c
```

## <a name="remarks"></a>Comentários

Compilando com **/c** cria somente os arquivos. obj. Você deve chamar o LINK explicitamente com as opções para executar a fase de vinculação da compilação e os arquivos corretos.

Qualquer projeto interno criado no ambiente de desenvolvimento usa o **/c** opção por padrão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

- Essa opção não está disponível de dentro do ambiente de desenvolvimento.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Para definir programaticamente essa opção do compilador, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileOnly%2A>.

## <a name="example"></a>Exemplo

A linha de comando a seguir cria os arquivos de objeto FIRST.obj e SECOND.obj. THIRD.obj é ignorado.

```
CL /c FIRST.C SECOND.C THIRD.OBJ
```

Para criar um arquivo executável, você deve chamar o LINK:

```
LINK firsti.obj second.obj third.obj /OUT:filename.exe
```

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
