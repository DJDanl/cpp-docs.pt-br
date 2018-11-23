---
title: Implementar um ponto de conexão
ms.date: 11/12/2018
f1_keywords:
- vc.codewiz.impl.cp.overview
helpviewer_keywords:
- connection points [C++], implementing
- implement connection point wizard [C++]
ms.assetid: 5b37e4f9-73c9-4bef-b26d-365bc0662260
ms.openlocfilehash: 7afa61246c5251936967e281f7237dc37e5be045
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693276"
---
# <a name="implement-a-connection-point"></a>Implementar um ponto de conexão

Para implementar um ponto de conexão usando o Assistente para Implementação de Ponto de Conexão, você precisa ter criado um projeto como um aplicativo ATL COM ou como um aplicativo MFC que contém suporte para ATL. Use o [assistente de projeto ATL](../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao aplicativo MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.

> [!NOTE]
> Para obter informações sobre como implementar pontos de conexão para um projeto MFC, confira [Pontos de conexão](../mfc/connection-points.md).

Depois de criar o projeto, para implementar um ponto de conexão, adicione primeiro um objeto ATL. Confira [Adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionam objetos ao projeto ATL.

> [!NOTE]
> O assistente não dá suporte a caixas de diálogo da ATL, serviços Web XML criados com o servidor ATL, objetos de desempenho ou contadores de desempenho.

Um objeto conectável (ou seja, uma fonte) pode mostrar um ponto de conexão para cada uma de suas interfaces de saída. Cada interface de saída pode ser implementada por um cliente em um objeto (ou seja, um coletor). Para obter mais informações, confira [pontos de conexão da ATL](../atl/atl-connection-points.md).

**Para implementar um ponto de conexão:**

1. Em Modo de Exibição de Classe, clique com o botão direito do mouse no nome da classe do objeto ATL.

1. Selecione **Adicionar** no menu de atalho e, em seguida, selecione **Adicionar Ponto de Conexão** para exibir o [assistente para implementação de ponto de conexão](#implement-connection-point-wizard).

1. Selecione as interfaces do ponto de conexão a serem implementadas nas bibliotecas de tipos apropriadas e selecione **Concluir**.

1. Em Modo de Exibição de Classe, examine as classes proxy criadas para cada ponto de conexão. As classes são exibidas como CProxy*InterfaceName*\<T> e são derivadas de [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md).

1. Clique duas vezes na classe do ponto de conexão para exibir a definição da classe do ponto de conexão.

   - Se você implementar um ponto de conexão para a interface de seu próprio projeto, a seguinte definição será exibida:

     ```cpp
     template< class T >
     class CProxyInterfaceName :
     public IConnectionPointImpl< T, &IID_InterfaceName >
     {
     public:
     };
     ```

   - Se você implementar uma interface local, as propriedades e os métodos serão exibidos no corpo da classe.

   - Se você implementar um ponto de conexão para outra interface, a definição incluirá os métodos da interface, cada um precedido por `Fire_`.

## <a name="in-this-section"></a>Nesta seção

- [Assistente de implementação de pontos de conexão](#implement-connection-point-wizard)

## <a name="implement-connection-point-wizard"></a>Assistente de implementação de pontos de conexão

Este assistente implementa um ponto de conexão para um objeto COM. Um objeto conectável (ou seja, uma fonte) pode mostrar um ponto de conexão para suas próprias interfaces ou para qualquer interface de saída. O Visual C++ e o Windows fornecem bibliotecas de tipos que têm interfaces de saída. Cada interface de saída pode ser implementada por um cliente em um objeto (ou seja, um coletor).

Para obter mais informações, confira [pontos de conexão da ATL](../atl/atl-connection-points.md).

- **Bibliotecas de tipos disponíveis**

  Exibe as bibliotecas de tipos disponíveis que guardam as definições de interface para as quais você pode implementar pontos de conexão. Selecione o botão de reticências para localizar um arquivo que tenha a biblioteca de tipos a ser usada.

- **Local**

  Exibe o local da biblioteca de tipos atualmente selecionada na lista **Bibliotecas de tipos disponíveis**.

- **Interfaces**

  Exibe as interfaces cujas definições estão guardadas na biblioteca de tipos atualmente selecionada na caixa **Bibliotecas de tipos disponíveis**.

  |Botão de transferência|Descrição|
  |---------------------|-----------------|
  |**>**|Adiciona à lista **Implementar pontos de conexão** o nome da interface atualmente selecionado na lista **Interfaces**.|
  |**>>**|Adiciona à lista **Implementar pontos de conexão** todos os nomes de interfaces disponíveis na lista **Interfaces**.|
  |**\<**|Remove o nome da interface atualmente selecionado na lista **Implementar pontos de conexão**.|
  |**\<\<**|Remove todos os nomes de interfaces atualmente relacionados na lista **Implementar pontos de conexão**.|

- **Implementar pontos de conexão**

  Exibe os nomes das interfaces nas quais você implementa pontos de conexão quando seleciona **Concluir**.
