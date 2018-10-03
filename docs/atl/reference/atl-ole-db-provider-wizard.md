---
title: Assistente de provedor ATL OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.provider.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL OLE DB Provider Wizard
- ATL projects, adding ATL OLE DB providers
ms.assetid: cf91ba78-01d1-4d12-b673-e95d96bfbebe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6857bf80aaaad36b4dcfc4fbf1330eccd03f971a
ms.sourcegitcommit: d1527eb2d50156bf923f2a32ec3af9efc7fc4304
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48250348"
---
# <a name="atl-ole-db-provider-wizard"></a>Assistente de provedor ATL OLE DB

Este assistente cria as classes que compõem um provedor OLE DB.

> [!WARNING]
> No Visual Studio 2017 versão 15,9 este assistente de código foi preterido e será removido em uma versão futura do Visual Studio. Este assistente é raramente usado. Suporte geral para ATL e MFC não é afetado pela remoção desse assistente. Se você quiser compartilhar seus comentários sobre essa substituição, conclua [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Sua opinião é importante para nós.


## <a name="remarks"></a>Comentários

A partir do Visual Studio 2008, o script de registro produzido por este assistente registrará seus componentes COM sob **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina as **registrar o componente para todos os usuários** opção do Assistente da ATL.

A tabela a seguir descreve as opções para o ATL OLE DB Provider Wizard:

- **Nome curto**

   Digite o nome curto do provedor a ser criado. As outras caixas de edição do assistente serão preenchido automaticamente com base no que você digitar aqui. Se desejar, você pode editar as outras caixas de nome.

- **Coclass**

   O nome da coclass. O nome de ProgID será alterado de acordo com esse nome.

- **Atribuído**

   Esta opção especifica se o assistente criará as classes de provedor usando atributos ou declarações de modelo. Quando você seleciona essa opção, o assistente usa atributos em vez de declarações de modelo (essa é a opção padrão se você tiver criado um projeto atribuído). Quando você desmarca essa opção, o assistente usa declarações de modelo em vez de atributos (essa é a opção padrão se você tiver criado um projeto não atribuído).

   Se você selecionar essa opção quando você criou um projeto não atribuído, o assistente o avisará que o projeto será convertido em um projeto atribuído e pergunta se você deseja continuar ou não.

- **ProgID**

   O ProgID ou o identificador programático, é uma cadeia de caracteres de texto que seu aplicativo pode usar em vez de um GUID. O nome de ProgID tem o formato *nomedacoclass*.

- **Versão**

   O número de versão do seu provedor. O padrão é 1.

- **Classe de fonte de dados**

   O nome da classe de fonte de dados do formulário C*Shortname*código-fonte.

- **Arquivo. h da fonte de dados**

   O arquivo de cabeçalho para a classe de fonte de dados. Você pode editar o nome do arquivo ou selecionar um arquivo de cabeçalho existente.

- **Classe da sessão**

   O nome da classe de sessão, de forma C*Shortname*sessão.

- **Arquivo. h de sessão**

   O arquivo de cabeçalho para a classe de sessão. Você pode editar o nome do arquivo ou selecionar um arquivo de cabeçalho existente.

- **Classe de comando**

   O nome da classe de comando, da forma C*Shortname*comando.

- **Arquivo. h de comando**

   O arquivo de cabeçalho para a classe de comando. Esse nome não pode ser editado e depende do nome do arquivo de cabeçalho do conjunto de linhas.

- **Classe de conjunto de linhas**

   O nome da classe de conjunto de linhas, da forma C*Shortname*conjunto de linhas.

- **Arquivo do conjunto de linhas. h**

   O arquivo de cabeçalho para a classe de conjunto de linhas. Você pode editar o nome do arquivo ou selecionar um arquivo de cabeçalho existente.

- **Arquivo. cpp do conjunto de linhas**

   Arquivo de implementação do provedor. Você pode editar o nome do arquivo ou selecionar um arquivo de implementação existente.

## <a name="see-also"></a>Consulte também

[Provedor ATL OLE DB](../../atl/reference/adding-an-atl-ole-db-provider.md)

