---
title: '/ZC: forScope (forçar conformidade para escopo de Loop) | Microsoft Docs'
ms.custom: ''
ms.date: 03/06/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.ForceConformanceInForLoopScope
- VC.Project.VCCLWCECompilerTool.ForceConformanceInForLoopScope
- /zc:forScope
dev_langs:
- C++
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: 3031f02d-3b14-4ad0-869e-22b0110c3aed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b21c844cd29c7fb45e58f44fdf8eaae427b74235
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32378607"
---
# <a name="zcforscope-force-conformance-in-for-loop-scope"></a>/Zc:forScope (forçar conformidade para escopo de loop)

Usado para implementar o comportamento padrão do C++ para [para](../../cpp/for-statement-cpp.md) loops com extensões da Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).

## <a name="syntax"></a>Sintaxe

> **/Zc:forScope**[**-**]

## <a name="remarks"></a>Comentários

O comportamento padrão é permitir que um **para** inicializador do loop estar fora do escopo após a **para** loop. Em **/Zc:forScope-** e [/Ze](../../build/reference/za-ze-disable-language-extensions.md), o **para** inicializador do loop permanece em escopo até que o escopo local termina.

O **/ZC: forScope** opção é ativada por padrão. **/ZC: forScope** não é afetada quando o [/ permissivo-](permissive-standards-conformance.md) opção é especificada.

O **/Zc:forScope-** opção é preterida e será removida em uma versão futura. O uso de **/Zc:forScope-** gera um aviso D9035 de substituição.

O código a seguir compila em **/Ze** , mas não em **/Za**:

```cpp
// zc_forScope.cpp
// compile by using: cl /Zc:forScope- /Za zc_forScope.cpp
// C2065, D9035 expected  
int main() {
    // Compile by using cl /Zc:forScope- zc_forScope.cpp
    // to compile this non-standard code as-is.
    // Uncomment the following line to resolve C2065 for /Za.
    // int i;
    for (int i = 0; i < 1; i++)
        ;
    i = 20;   // i has already gone out of scope under /Za
}
```

Se você usar **/Zc:forScope-**, aviso C4288 (desativado por padrão) é gerado se uma variável está no escopo devido a uma declaração que foi feita em um escopo anterior. Para demonstrar isso, remova o `//` caracteres no código de exemplo para declarar `int i`.

Você pode modificar o comportamento de tempo de execução **/ZC: forScope** usando o [está de acordo com](../../preprocessor/conform.md) pragma.

Se você usar **/Zc:forScope-** em um projeto que tem um arquivo. pch existente, um aviso será gerado, **/Zc:forScope-** é ignorado, e a compilação continua usando os arquivos. pch existentes. Se quiser que um novo arquivo. pch gerado, use [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md).

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **idioma** página de propriedades.

1. Modificar o **forçar conformidade para escopo de Loop** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ForceConformanceInForLoopScope%2A>.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
[/Za, /Ze (desabilitar extensões de linguagem)](../../build/reference/za-ze-disable-language-extensions.md)<br/>
