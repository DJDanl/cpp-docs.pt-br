---
title: -Zl (omitir nome da biblioteca padrão) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /zi
- VC.Project.VCCLCompilerTool.OmitDefaultLibName
dev_langs:
- C++
helpviewer_keywords:
- -Zl compiler option [C++]
- ZI compiler option
- Omit Default Library Name compiler option
- /Zl compiler option [C++]
- default libraries, omitting names
ms.assetid: b27d39d0-44d6-498c-84ae-27c1326fee59
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3f09abebb8fc142bbe2390f61d790a5885c9aebe
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707311"
---
# <a name="zl-omit-default-library-name"></a>/Zl (omitir nome da biblioteca padrão)

Omite o nome da biblioteca padrão C em tempo de execução do arquivo. obj. Por padrão, o compilador coloca o nome da biblioteca no arquivo .obj para direcionar o vinculador à biblioteca correta.

## <a name="syntax"></a>Sintaxe

```
/Zl
```

## <a name="remarks"></a>Comentários

Para obter mais informações sobre a biblioteca padrão, consulte [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md).

Você pode usar **/Zl** para compilar os arquivos. obj que você planeja colocar em uma biblioteca. Embora a omitir o nome da biblioteca salva apenas uma pequena quantidade de espaço para um arquivo. obj único, o espaço total salvado é significativo em uma biblioteca que contém muitos módulos de objeto.

Essa opção é uma opção avançada. Essa opção remove determinado suporte de biblioteca de tempo de execução C que pode ser exigida pelo seu aplicativo, resultando em erros de tempo de vinculação, se seu aplicativo depende desse suporte. Se você usar essa opção, você deve fornecer os componentes necessários de alguma outra forma.

Use [/NODEFAULTLIB (ignorar bibliotecas)](../../build/reference/nodefaultlib-ignore-libraries.md). para direcionar o vinculador para ignorar as referências da biblioteca em todos os arquivos. obj.

Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

Ao compilar com **/Zl**, `_VC_NODEFAULTLIB` está definido.  Por exemplo:

```
// vc_nodefaultlib.cpp
// compile with: /Zl
void Test() {
   #ifdef _VC_NODEFAULTLIB
      int i;
   #endif

   int i;   // C2086
}
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **omitir os nomes de bibliotecas padrão** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitDefaultLibName%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)