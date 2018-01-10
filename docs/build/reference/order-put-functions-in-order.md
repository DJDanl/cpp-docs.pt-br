---
title: "-ORDEM (colocar funções na ordem) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.FunctionOrder
- /order
dev_langs: C++
helpviewer_keywords:
- ORDER linker option
- -ORDER linker option
- LINK tool [C++], program optimizing
- /ORDER linker option
- LINK tool [C++], swap tuning
- paging, optimizing
ms.assetid: ecf5eb3e-e404-4e86-9a91-4e5ec157261a
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2264296d288f9105a59c0ac5099c1dedef55ee2f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="order-put-functions-in-order"></a>/ORDER (colocar funções na ordem)

Especifique a ordem do link para as funções de (COMDAT) empacotadas separadamente.

## <a name="syntax"></a>Sintaxe

>/ PEDIDO: @*filename*

### <a name="parameters"></a>Parâmetros

*filename*  
Um arquivo de texto que especifica a ordem dos links para as funções COMDAT.

## <a name="remarks"></a>Comentários

O **/ORDER** opção de compilador permite otimizar o comportamento de paginação do programa com o agrupamento de uma função junto com as funções que ele chama. Você também pode agrupar as funções de chamada com frequência. Essas técnicas, conhecidas como *ajuste swap* ou *otimização paginação*, aumentar a probabilidade de uma função chamada estiver na memória quando necessário e não precisa ser paginada do disco.

Quando você compila seu código-fonte em um arquivo de objeto, você pode informar ao compilador para colocar cada função em sua própria seção chamada um *COMDAT*, usando o [/Gy (habilitar vinculação do nível de função)](../../build/reference/gy-enable-function-level-linking.md) compilador opção. O **/ORDER** opção de vinculador informa o vinculador para colocar COMDATs na imagem executável na ordem em que você especificar.

Para especificar a ordem COMDAT, crie um *arquivo de resposta*, um arquivo de texto que lista cada COMDAT por nome, um por linha, na ordem em que você deseja que eles sejam colocados pelo vinculador. Passe o nome desse arquivo como o *filename* parâmetro o **/ORDER** opção. Para funções C++, o nome de um COMDAT é decorado formato do nome da função. Use o nome não decorado para funções de C, `main`, e para funções C++ é declarado como `extern "C"`. Nomes de função e nomes decorados diferenciam maiusculas de minúsculas. Para obter mais informações sobre nomes decorados, consulte [nomes decorados](../../build/reference/decorated-names.md). 

Para localizar os nomes decorados de seu COMDATs, use o [DUMPBIN](../../build/reference/dumpbin-reference.md) da ferramenta [/símbolos](../../build/reference/symbols.md) opção no arquivo de objeto. O vinculador automaticamente precede um sublinhado (\_) para a função na resposta, os nomes de arquivo, a menos que o nome começa com um ponto de interrogação (?) ou sinal de arroba (@). Por exemplo, se um arquivo de origem, example.cpp, contém funções `int cpp_func(int)`, `extern "C" int c_func(int)` e `int main(void)`, o comando `DUMPBIN /SYMBOLS example.obj` lista esses nomes decorados:

```Output
...
088 00000000 SECT1A notype ()    External     | ?cpp_func@@YAHH@Z (int __cdecl cpp_func(int))
089 00000000 SECT22 notype ()    External     | _c_func
08A 00000000 SECT24 notype ()    External     | _main
...
```

Nesse caso, especifique os nomes como `?cpp_func@@YAHH@Z`, `c_func`, e `main` em seu arquivo de resposta.

Se mais de um **/ORDER** opção aparecerá nas opções de vinculador, o último deles especificado entra em vigor.

O **/ORDER** opção desabilita o vínculo incremental. Você pode ver um aviso de vinculador [LNK4075](../../error-messages/tool-errors/linker-tools-warning-lnk4075.md) quando você especificar essa opção se o vínculo incremental estiver habilitado, ou se você tiver especificado o [/ZI (Incremental PDB)](../../build/reference/z7-zi-zi-debug-information-format.md) opção de compilador. Para este aviso de silêncio, você pode usar o [/incremental: no](../../build/reference/incremental-link-incrementally.md) opção de vinculador para desativar o vínculo incremental e usar o [/Zi (gerar PDB)](../../build/reference/z7-zi-zi-debug-information-format.md) opção de compilador para gerar um PDB sem vínculo incremental.

> [!NOTE]
> LINK não é possível ordenar funções estáticas, como nomes de função estática não são nomes de símbolos públicos. Quando **/ORDER** for especificado, de aviso de vinculador [LNK4037](../../error-messages/tool-errors/linker-tools-warning-lnk4037.md) é gerado para cada símbolo no arquivo de resposta de ordem é estática ou não foi encontrado.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  

1. Em **propriedades de configuração**, abra **vinculador** e, em seguida, escolha o **otimização** página de propriedades.

1. Modificar o **ordem de função** propriedade para conter o nome do seu arquivo de resposta.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.FunctionOrder%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)  
[Opções do vinculador](../../build/reference/linker-options.md)