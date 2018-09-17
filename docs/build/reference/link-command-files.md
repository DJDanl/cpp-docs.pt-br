---
title: Arquivos de comando LINK | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- link
dev_langs:
- C++
helpviewer_keywords:
- syntax, LINK command files
- command files [C++]
- LINK tool [C++]
- text files, passing arguments to LINK
- LINK tool [C++], command-line syntax
- command files [C++], LINK
ms.assetid: 7154511c-32b9-4e5b-a515-3922fa9de48e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2611fc0c16e4ff30d7802989518ca8c5d8dc33af
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713708"
---
# <a name="link-command-files"></a>Arquivos de comando LINK

Você pode passar argumentos de linha de comando para o LINK na forma de um arquivo de comando. Para especificar um arquivo de comando para o vinculador, use a seguinte sintaxe:

> **LINK \@**  <em>commandfile</em>

O *commandfile* é o nome de um arquivo de texto. Nenhum espaço ou tabulação é permitida entre o sinal de arroba (**\@**) e o nome do arquivo. Não há nenhuma extensão padrão; Você deve especificar o nome de arquivo completo, incluindo qualquer extensão. Caracteres curinga não pode ser usada. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo. LINK não usa uma variável de ambiente para pesquisar o arquivo.

No arquivo de comando, argumentos podem ser separados por espaços ou tabulações (como na linha de comando) e por caracteres de nova linha.

Você pode especificar todos ou parte da linha de comando em um arquivo de comando. Você pode usar mais de um arquivo de comando em um comando LINK. LINK aceita a entrada do arquivo de comando, como se ele foi especificado no local na linha de comando. Arquivos de comando não podem ser aninhados. LINK exibe o conteúdo dos arquivos de comando, a menos que o [/NOLOGO](../../build/reference/nologo-suppress-startup-banner-linker.md) opção for especificada.

## <a name="example"></a>Exemplo

O comando a seguir para criar uma DLL passa os nomes dos arquivos de objeto e bibliotecas em arquivos separados de comando e usa um terceiro arquivo para a especificação da opção/exportações de comando:

```cmd
link /dll @objlist.txt @liblist.txt @exports.txt
```

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)