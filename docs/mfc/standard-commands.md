---
title: Comandos padrão
ms.date: 11/04/2016
helpviewer_keywords:
- File menu
- identifiers [MFC], command IDs
- command IDs, standard commands
- OLE commands
- commands [MFC], standard
- standard command IDs
- Window menu commands
- standard commands
- View menu commands
- Edit menu standard commands
- Help [MFC], menus
- programmer-defined IDs [MFC]
ms.assetid: 88cf3ab4-79b3-4ac6-9365-8ac561036fbf
ms.openlocfilehash: fa98a250e6f9de3005cf4978fe66689363865879
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50485690"
---
# <a name="standard-commands"></a>Comandos padrão

O framework define várias mensagens de comando padrão. Normalmente, as IDs para esses comandos assumem a forma:

**ID _** *código-fonte*_*Item*

em que *fonte* geralmente é um nome de menu e *Item* é um item de menu. Por exemplo, a ID de comando para o comando novo no menu arquivo é ID_FILE_NEW. IDs de comando padrão são mostradas em negrito na documentação. IDs definidos pelo programador são mostrados em uma fonte diferente do texto ao redor.

A seguir está uma lista de alguns dos comandos mais importantes com suporte:

*Comandos do Menu arquivo*<br/>
Novo, abrir, fechar, salvar, salvar como, Configurar página, Configurar impressão, impressão, visualização de impressão, sair e arquivos usados mais recentemente.

*Comandos do Menu Editar*<br/>
Claro, Clear All, copiar, cortar, Find, colar, repetir, Replace, selecionar tudo, desfazer e refazer.

*Comandos do menu Exibir*<br/>
Barra de ferramentas e barra de Status.

*Comandos do menu Janela*<br/>
Novo, organizar, em cascata, lado a lado Horizontal, Vertical de bloco e dividir.

*Comandos do menu Ajuda*<br/>
Indexar, usando a Ajuda e sobre.

*Comandos OLE (Menu Editar)*<br/>
Inserir novo objeto, Editar Links, Colar vínculo, Colar especial, e *typename* (comandos de verbo) do objeto.

O framework fornece diferentes níveis de suporte para estes comandos. Alguns comandos só têm suporte como IDs de comando definidos, enquanto outros são compatíveis com implementações completas. Por exemplo, a estrutura implementa o comando Abrir no menu Arquivo, criando um novo objeto de documento, exibindo uma caixa de diálogo Abrir e abrir e ler o arquivo. Por outro lado, você deve implementar comandos no menu Editar por conta própria, uma vez que comandos como ID_EDIT_COPY dependerão da natureza dos dados que você está copiando.

Para obter mais informações sobre os comandos com suporte e o nível de implementação fornecida, consulte [22 de observação técnica](../mfc/tn022-standard-commands-implementation.md). Os comandos padrão são definidos no arquivo AFXRES. H.

## <a name="see-also"></a>Consulte também

[Objetos da interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)

