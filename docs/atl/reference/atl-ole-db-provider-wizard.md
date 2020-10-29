---
title: Assistente de provedor OLE DB da ATL
ms.date: 05/09/2019
helpviewer_keywords:
- ATL projects, adding ATL OLE DB providers
ms.assetid: cf91ba78-01d1-4d12-b673-e95d96bfbebe
ms.openlocfilehash: 43b8ed4507b004f1e78bc1b9dda64c44ff56e1d7
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921133"
---
# <a name="atl-ole-db-provider-wizard"></a>Assistente de provedor OLE DB da ATL

::: moniker range="msvc-160"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=msvc-150"

## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por esse assistente registra seus componentes COM em **HKEY_CURRENT_USER** , e não em **HKEY_LOCAL_MACHINE** . Para modificar esse comportamento, defina a opção **Registrar componente para todos os usuários** do Assistente da ATL.

A tabela a seguir descreve as opções para o Assistente de Provedor OLE DB da ATL:

- **Nome curto**

   Digite o nome curto do provedor a ser criado. As outras caixas de edição do assistente serão preenchidas automaticamente com base no que você digitar aqui. É possível editar as outras caixas de nome se desejar.

- **Coclass**

   O nome da coclass. O nome de ProgID será alterado para corresponder a esse nome.

- **Atribuído**

   Essa opção especifica se o assistente criará as classes de provedor usando atributos ou declarações de modelo. Quando essa opção é selecionada, o assistente usa atributos em vez de declarações de modelo (essa será a opção padrão se você tiver criado um projeto atribuído). Ao desmarcar essa opção, o assistente usa declarações de modelo no lugar de atributos (isto é, a opção padrão se você tiver criado um projeto não atribuído).

   Se você tiver selecionado essa opção quando criou um projeto não atribuído, o assistente avisará que o projeto será convertido em um projeto atribuído e pedirá que opte por continuar ou não.

- **ProgID**

   ProgID, ou identificador programático, é uma cadeia de caracteres de texto que o aplicativo pode usar no lugar de um GUID. O nome de ProgID tem o formato *Projectname.Coclassname* .

- **Versão**

   O número da versão do seu provedor. O padrão é 1.

- **Classe DataSource**

   O nome da classe da fonte de dados, no formato C *Nomecurto* Origem.

- **Arquivo .h de DataSource**

   O arquivo de cabeçalho para a classe da fonte de dados. Você pode editar o nome desse arquivo ou selecionar um arquivo de cabeçalho existente.

- **Classe da sessão**

   O nome da classe da sessão, no formato C *Nomecurto* Sessão.

- **Arquivo. h da sessão**

   O arquivo de cabeçalho da classes da sessão. Você pode editar o nome desse arquivo ou selecionar um arquivo de cabeçalho existente.

- **Classe do comando**

   O nome da classe do comando, no formato C *Nomecurto* Comando.

- **Arquivo .h do comando**

   O arquivo de cabeçalho da classe do comando. Esse nome não pode ser editado e depende do nome do arquivo de cabeçalho do conjunto de linhas.

- **Classe do conjunto de linhas**

   O nome da classe do conjunto de linhas, no formato C *Nomecurto* ConjuntoDeLinhas.

- **Arquivo. h do conjunto de linhas**

   O arquivo de cabeçalho da classe do conjunto de linhas. Você pode editar o nome desse arquivo ou selecionar um arquivo de cabeçalho existente.

- **Arquivo .cpp do conjunto de linhas**

   O arquivo de implementação do provedor. Você pode editar o nome desse arquivo ou selecionar um arquivo de implementação existente.

::: moniker-end

## <a name="see-also"></a>Veja também

[Provedor OLE DB da ATL](../../atl/reference/adding-an-atl-ole-db-provider.md)
