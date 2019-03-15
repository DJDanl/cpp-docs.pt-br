---
title: /ORDER (colocar funções na ordem)
ms.date: 09/05/2018
f1_keywords:
- VC.Project.VCLinkerTool.FunctionOrder
- /order
helpviewer_keywords:
- ORDER linker option
- -ORDER linker option
- LINK tool [C++], program optimizing
- /ORDER linker option
- LINK tool [C++], swap tuning
- paging, optimizing
ms.assetid: ecf5eb3e-e404-4e86-9a91-4e5ec157261a
ms.openlocfilehash: b1927ffd2efc923157fe1956fe905c939bc62719
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57807878"
---
# <a name="order-put-functions-in-order"></a>/ORDER (colocar funções na ordem)

Especifique a ordem de vinculação para funções de (COMDAT) empacotadas separadamente.

## <a name="syntax"></a>Sintaxe

> **/ORDER:\@**<em>filename</em>

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Um arquivo de texto que especifica a ordem de vinculação para funções COMDAT.

## <a name="remarks"></a>Comentários

O **/ORDER** opção de compilador permite que você otimize o comportamento de paginação do programa através do agrupamento de uma função junto com as funções que ele chama. Você também pode agrupar funções chamadas com frequência. Essas técnicas, conhecidas como *ajuste swap* ou *otimização paginação*, aumentar a probabilidade de que uma função chamada está na memória quando necessário e não tem que ser paginada do disco.

Quando você compilar seu código-fonte em um arquivo de objeto, você pode dizer ao compilador para colocar cada função em sua própria seção, chamada um *COMDAT*, usando o [/Gy (habilitar vinculação do nível de função)](gy-enable-function-level-linking.md) compilador opção. O **/ORDER** a opção de vinculador instrui o vinculador a colocar COMDATs na imagem executável na ordem em que você especificar.

Para especificar a ordem COMDAT, crie uma *arquivo de resposta*, um arquivo de texto que lista cada COMDAT por nome, um por linha, na ordem em que você deseja que eles sejam colocados pelo vinculador. Passe o nome desse arquivo como o *filename* parâmetro do **/ORDER** opção. Para funções C++, o nome de uma COMDAT é a forma decorada do nome da função. Use o nome não decorado para funções de C `main`, e para funções C++ declaradas como `extern "C"`. Nomes de função e os nomes decorados diferenciam maiusculas de minúsculas. Para obter mais informações sobre nomes decorados, consulte [nomes decorados](decorated-names.md).

Para localizar os nomes decorados de seu COMDATs, use o [DUMPBIN](dumpbin-reference.md) da ferramenta [/símbolos](symbols.md) opção no arquivo de objeto. O vinculador automaticamente precede um caractere de sublinhado (**\_**) para a função na resposta, os nomes de arquivo, a menos que o nome começa com um ponto de interrogação (**?**) ou sinal de arroba ( **\@**). Por exemplo, se um arquivo de origem, example.cpp, contém funções `int cpp_func(int)`, `extern "C" int c_func(int)` e `int main(void)`, o comando `DUMPBIN /SYMBOLS example.obj` lista esses nomes decorados:

```Output
...
088 00000000 SECT1A notype ()    External     | ?cpp_func@@YAHH@Z (int __cdecl cpp_func(int))
089 00000000 SECT22 notype ()    External     | _c_func
08A 00000000 SECT24 notype ()    External     | _main
...
```

Nesse caso, especifique os nomes conforme `?cpp_func@@YAHH@Z`, `c_func`, e `main` em seu arquivo de resposta.

Se mais de um **/ORDER** opção aparecerá nas opções do vinculador, o último deles especificado entra em vigor.

O **/ORDER** opção desabilita a vinculação incremental. Você pode ver avisos de vinculador [LNK4075](../../error-messages/tool-errors/linker-tools-warning-lnk4075.md) quando você especificar essa opção se a vinculação incremental estiver habilitada, ou se você tiver especificado o [/ZI (PDB Incremental)](z7-zi-zi-debug-information-format.md) opção de compilador. Para silenciar esse aviso, você pode usar o [/incremental: no](incremental-link-incrementally.md) opção de vinculador para desativar a vinculação incremental e usar o [/Zi (gerar PDB)](z7-zi-zi-debug-information-format.md) opção do compilador para gerar um PDB sem vinculação incremental.

> [!NOTE]
> LINK não é possível ordenar funções estáticas, como nomes de função estática não são nomes de símbolos públicos. Quando **/ORDER** for especificado, avisos de vinculador [LNK4037](../../error-messages/tool-errors/linker-tools-warning-lnk4037.md) é gerado para cada símbolo no arquivo de resposta de ordem é estática ou não foi encontrado.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. Modificar a **ordem de função** propriedade para conter o nome do seu arquivo de resposta.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.FunctionOrder%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
