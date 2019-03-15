---
title: /VMM, - vms, - vmv (representação de finalidade geral)
ms.date: 11/04/2016
f1_keywords:
- /vms
- /vmm
- /vmv
helpviewer_keywords:
- Virtual Inheritance compiler option
- general purpose representation compiler options
- vms compiler option [C++]
- vmm compiler option [C++]
- /vmm compiler option [C++]
- -vmm compiler option [C++]
- -vms compiler option [C++]
- /vms compiler option [C++]
- vmv compiler option [C++]
- /vmv compiler option [C++]
- Single Inheritance compiler option
- -vmv compiler option [C++]
ms.assetid: 0fcd7ae0-3031-4c62-a2a8-e154c8685dae
ms.openlocfilehash: 7a46cecdbf96ad891ce218df4769a60590e562a9
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57810036"
---
# <a name="vmm-vms-vmv-general-purpose-representation"></a>/vmm, /vms, /vmv (representação de finalidade geral)

Usado quando [/vmb, /vmg (método de representação)](vmb-vmg-representation-method.md) está selecionado como o [método de representação](vmb-vmg-representation-method.md). Essas opções indicam o modelo de herança da definição de classe ainda não encontrado.

## <a name="syntax"></a>Sintaxe

```
/vmm
/vms
/vmv
```

## <a name="remarks"></a>Comentários

As opções são descritas na tabela a seguir.

|Opção|Descrição|
|------------|-----------------|
|**/vmm**|Especifica a representação mais geral de um ponteiro para um membro de uma classe para ser um que usa herança múltipla.<br /><br /> Correspondente [palavra-chave de herança](../../cpp/inheritance-keywords.md) e o argumento [#pragma pointers_to_members](../../preprocessor/pointers-to-members.md) está **multiple_inheritance**.<br /><br /> Essa representação é maior do que o necessário para a herança única.<br /><br /> Se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado é virtual, o compilador gera um erro.|
|**/vms**|Especifica a representação mais geral de um ponteiro para um membro de uma classe para ser um que não usa herança única ou nenhuma herança.<br /><br /> Correspondente [palavra-chave de herança](../../cpp/inheritance-keywords.md) e o argumento [#pragma pointers_to_members](../../preprocessor/pointers-to-members.md) está **single_inheritance**.<br /><br /> Isso é a menor representação possível de um ponteiro para um membro de uma classe.<br /><br /> Se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado é múltiplo ou virtual, o compilador gera um erro.|
|**/vmv**|Especifica a representação mais geral de um ponteiro para um membro de uma classe para ser um que usa herança virtual. Ele nunca faz com que um erro e é o padrão.<br /><br /> Correspondente [palavra-chave de herança](../../cpp/inheritance-keywords.md) e o argumento [#pragma pointers_to_members](../../preprocessor/pointers-to-members.md) está **virtual_inheritance**.<br /><br /> Essa opção requer um ponteiro maior e o código adicional para interpretar o ponteiro que as outras opções.|

Quando você especificar uma dessas opções de modelo de herança, esse modelo é usado para todos os ponteiros para membros de classe, independentemente de seu tipo de herança ou se o ponteiro é declarado antes ou depois da classe. Portanto, se você sempre usar classes de herança simples, você pode reduzir o tamanho de código compilando com **/vms**; no entanto, se você quiser usar o caso mais geral (a custa a representação de dados maior), compilar com **/vmv**.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[/vmb, /vmg (método de representação)](vmb-vmg-representation-method.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
