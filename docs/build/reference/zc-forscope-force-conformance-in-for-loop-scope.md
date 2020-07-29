---
title: /Zc:forScope (forçar conformidade para escopo de loop)
ms.date: 03/06/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.ForceConformanceInForLoopScope
- VC.Project.VCCLWCECompilerTool.ForceConformanceInForLoopScope
- /zc:forScope
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: 3031f02d-3b14-4ad0-869e-22b0110c3aed
ms.openlocfilehash: b1173ad609a1b2c95d6cf118f4e2d5defeec5b9c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234335"
---
# <a name="zcforscope-force-conformance-in-for-loop-scope"></a>/Zc:forScope (forçar conformidade para escopo de loop)

Usado para implementar o comportamento padrão do C++ para loops [do for](../../cpp/for-statement-cpp.md) com extensões da Microsoft ([/ze](za-ze-disable-language-extensions.md)).

## <a name="syntax"></a>Sintaxe

> **/Zc: forScope**[ **-** ]

## <a name="remarks"></a>Comentários

O comportamento padrão é deixar **`for`** o inicializador de um loop sair do escopo após o **`for`** loop. Em **/Zc: forScope-** e [/ze](za-ze-disable-language-extensions.md), o **`for`** inicializador do loop permanece no escopo até que o escopo local termine.

A opção **/Zc: forScope** está ativada por padrão. **/Zc: forScope** não é afetado quando a opção [/permissive-](permissive-standards-conformance.md) é especificada.

A opção **/Zc: forScope-** foi preterida e será removida em uma versão futura. Uso de **/Zc: forScope-** gera D9035 de aviso de reprovação.

O código a seguir é compilado em **/ze** , mas não em **/za**:

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

Se você usar **/Zc: forScope-**, C4288 de aviso (desativado por padrão) será gerado se uma variável estiver no escopo devido a uma declaração que foi feita em um escopo anterior. Para demonstrar isso, remova os `//` caracteres no código de exemplo para declará-los `int i` .

Você pode modificar o comportamento de tempo de execução de **/Zc: forScope** usando o pragma de [conformidade](../../preprocessor/conform.md) .

Se você usar **/Zc: forScope-** em um projeto que tenha um arquivo. pch existente, um aviso será gerado, **/Zc: forScope-** será ignorado e a compilação continuará usando os arquivos. pch existentes. Se você quiser um novo arquivo. pch gerado, use [/Yc (criar arquivo de cabeçalho pré-compilado)](yc-create-precompiled-header-file.md).

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**página de propriedades de  >  **linguagem C/C++** Properties  >  **Language** .

1. Modifique a propriedade **forçar conformidade no escopo do loop for** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ForceConformanceInForLoopScope%2A>.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)<br/>
[/Za,/Ze (desabilitar extensões de linguagem)](za-ze-disable-language-extensions.md)<br/>
