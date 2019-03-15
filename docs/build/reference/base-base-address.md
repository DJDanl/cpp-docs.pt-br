---
title: /BASE (endereço básico)
ms.date: 09/05/2018
f1_keywords:
- /base
- VC.Project.VCLinkerTool.BaseAddress
helpviewer_keywords:
- base addresses [C++]
- programs [C++], preventing relocation
- semicolon [C++], specifier
- -BASE linker option
- key address size
- environment variables [C++], LIB
- programs [C++], base address
- LIB environment variable
- BASE linker option
- DLLs [C++], linking
- /BASE linker option
- '@ symbol for base address'
- executable files [C++], base address
- at sign symbol for base address
ms.assetid: 00b9f6fe-0bd2-4772-a69c-7365eb199069
ms.openlocfilehash: dc6380903af0be2e6696ca3589813c249f71dd05
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57812272"
---
# <a name="base-base-address"></a>/BASE (endereço básico)

Especifica o endereço base para um programa.

## <a name="syntax"></a>Sintaxe

> **/BASE:**{*address*[**,**<em>size</em>] | **\@**<em>filename</em>**,**<em>key</em>}

## <a name="remarks"></a>Comentários

> [!NOTE]
> Por motivos de segurança, a Microsoft recomenda que você use o [/DYNAMICBASE](dynamicbase-use-address-space-layout-randomization.md) opção em vez de especificar os endereços base para seus executáveis. Isso gera uma imagem executável que possa ter REBASE aleatória no momento do carregamento usando o recurso de aleatoriedade (ASLR) de layout de espaço de endereço do Windows. A opção de /DYNAMICBASE está ativada por padrão.

A opção BASE define um endereço base para o programa, substituindo o local padrão para um .exe ou o arquivo DLL. O endereço de base padrão para um arquivo .exe é 0x400000 para imagens de 32 bits ou 0x140000000 para imagens de 64 bits. Para uma DLL, o endereço básico padrão é 0x10000000 para imagens de 32 bits ou 0x180000000 para imagens de 64 bits. Em sistemas operacionais que não suportam a randomização de layout de espaço de endereço (ASLR), ou quando a opção /DynamicBase: no foi definida, o sistema operacional primeiro tenta carregar um programa em seu especificado ou o endereço básico padrão. Se espaço suficiente não estiver disponível, o sistema realoca o programa. Para evitar a realocação, use o [/Fixed](fixed-fixed-base-address.md) opção.

O vinculador emitirá um erro se *endereço* não é um múltiplo de 64 K. Opcionalmente, você pode especificar o tamanho do programa; o vinculador emitirá um aviso se o programa não pode se ajustar no tamanho especificado.

Na linha de comando, outra maneira de especificar o endereço básico é usando um arquivo de resposta do endereço base. Um arquivo de resposta do endereço base é um arquivo de texto que contém os endereços base e os tamanhos opcionais de todas as DLLs seu programa irá usar e uma chave de texto exclusivo para cada endereço de base. Para especificar um endereço básico usando um arquivo de resposta, use um sinal de arroba (**\@**) seguido do nome de arquivo de resposta *filename*, seguido por uma vírgula, em seguida, a *chave*valor para o endereço básico usar no arquivo. O vinculador procura *filename* no caminho especificado, ou se nenhum caminho for especificado, nos diretórios especificados na variável de ambiente LIB. Cada linha na *filename* representa uma DLL e tem a seguinte sintaxe:

> *key* *address* [*size*] **;** *comment*

O *chave* é uma cadeia de caracteres alfanuméricos e não diferencia maiusculas de minúsculas. Ele geralmente é o nome de uma DLL, mas ele não precisa ser. O *chave* é seguido por uma base *endereço* na notação decimal, hexadecimal ou de linguagem C e um máximo de opcional *tamanho*. Todos os três argumentos são separados por espaços ou tabulações. O vinculador emitirá um aviso se especificado *tamanho* é menor que o espaço de endereço virtual exigido pelo programa. Um *comentário* é especificado por um ponto e vírgula (**;**) e pode ser na mesma ou em uma linha separada. O vinculador ignora todo o texto da vírgula ao final da linha. Este exemplo mostra parte de um arquivo desse tipo:

```
main   0x00010000    0x08000000    ; for PROJECT.exe
one    0x28000000    0x00100000    ; for DLLONE.DLL
two    0x28100000    0x00300000    ; for DLLTWO.DLL
```

Se o arquivo que contém essas linhas é chamado de DLLs, o comando de exemplo a seguir aplica-se essas informações:

```
link dlltwo.obj /dll /base:@dlls.txt,two
```

Outra maneira de definir o endereço base é usando o *BASE* argumento em uma [nome](name-c-cpp.md) ou [biblioteca](library.md) instrução. Opção /BASE e [/DLL](dll-build-a-dll.md) opções juntas são equivalentes para o **biblioteca** instrução.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **avançado** página de propriedades.

1. Modificar a **endereço de Base** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.BaseAddress%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
