---
title: Como adicionar um componente Active Server Page da ATL
ms.date: 05/09/2019
ms.assetid: 7be2204c-6e58-4099-8892-001b848c8987
ms.openlocfilehash: 08d49baa547342843b525f871de9570d4e752068
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921159"
---
# <a name="adding-an-atl-active-server-page-component"></a>Como adicionar um componente Active Server Page da ATL

::: moniker range="msvc-160"

O assistente do componente Active Server Pages da ATL não está disponível no Visual Studio 2019 e posterior.

::: moniker-end

::: moniker range="<=msvc-150"

Para adicionar um objeto da ATL (Active Template Library) ao seu projeto, ele deve ter sido criado como um aplicativo COM da ATL ou como um aplicativo MFC que contém suporte para ATL. É possível usar o [Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo da ATL, é possível selecionar **Adicionar Suporte para ATL ao MFC** na caixa de diálogo [Adicionar Caixa de Diálogo em Classe](../../ide/adding-a-class-visual-cpp.md#add-class-dialog-box) ou [adicionar um objeto da ATL ao seu aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte para ATL para um aplicativo MFC.

Os componentes do Active Server Pages fazem parte da arquitetura dos Serviços de Informações da Internet, que oferece os seguintes recursos de desenvolvimento da Web avançados:

- É possível inserir componentes do ASP às suas páginas HTML para criar conteúdo dinâmico e independente do navegador.

- É possível usar páginas do ASP para oferecer conectividade de banco de dados baseada em padrões.

- É possível usar as funcionalidades de tratamento de erro do ASP para seus aplicativos baseados em Web.

## <a name="to-add-an-atl-active-server-pages-component-to-your-project"></a>Para adicionar um componente do Active Server Pages da ATL ao seu projeto

1. No **Gerenciador de Soluções** , clique com o botão direito do mouse no nome do projeto ao qual você deseja adicionar o componente do Active Server Pages da ATL.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar classe** .

1. Na caixa de diálogo [Adicionar Classe](../../ide/adding-a-class-visual-cpp.md#add-class-dialog-box), no painel **Modelos** , clique em **Componente do Active Server Page da ATL** e, em seguida, clique em **Abrir** para exibir o [Assistente do Componente do Active Server Page da ATL](../../atl/reference/atl-active-server-page-component-wizard.md).

::: moniker-end

## <a name="see-also"></a>Veja também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma nova Interface em um projeto da ATL](../../atl/reference/adding-a-new-interface-in-an-atl-project.md)<br/>
[Adicionando pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md)<br/>
[Adicionando um método](../../ide/adding-a-method-visual-cpp.md)<br/>
[Classe MFC](../../mfc/reference/adding-an-mfc-class.md)<br/>
[Adicionando uma classe do C++ genérica](../../ide/adding-a-generic-cpp-class.md)
