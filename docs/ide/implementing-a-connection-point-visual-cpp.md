---
title: Implementando um ponto de conexão (Visual C++)
ms.date: 11/04/2016
helpviewer_keywords:
- Implement Connection Point Wizard [C++]
- connection points [C++], implementing
ms.assetid: 5b37e4f9-73c9-4bef-b26d-365bc0662260
ms.openlocfilehash: 45e3dfcfc7e7bcb9fcbe14e08a8c238fe9bec5a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50568318"
---
# <a name="implementing-a-connection-point-visual-c"></a>Implementando um ponto de conexão (Visual C++)

Para implementar um ponto de conexão usando o Assistente para Implementação de Ponto de Conexão, você precisa ter criado um projeto como um aplicativo ATL COM ou como um aplicativo MFC que contém suporte para ATL. Use o [Assistente de Projeto ATL](../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao aplicativo MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.

> [!NOTE]
>  Para obter informações sobre como implementar pontos de conexão para um projeto MFC, confira [Pontos de conexão](../mfc/connection-points.md).

Depois de criar o projeto, para implementar um ponto de conexão, adicione primeiro um objeto ATL. Confira [Adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionam objetos ao projeto ATL.

> [!NOTE]
>  O assistente não dá suporte a caixas de diálogo da ATL, serviços Web XML criados com o servidor ATL, objetos de desempenho ou contadores de desempenho.

Um objeto conectável (ou seja, uma fonte) pode expor um ponto de conexão para cada uma de suas interfaces de saída. Cada interface de saída pode ser implementada por um cliente em um objeto (ou seja, um coletor). Para obter mais informações, confira [Pontos de conexão da ATL](../atl/atl-connection-points.md).

### <a name="to-implement-a-connection-point"></a>Para implementar um ponto de conexão

1. Em Modo de Exibição de Classe, clique com o botão direito do mouse no nome da classe do objeto ATL.

1. Clique em **Adicionar** no menu de atalho e, em seguida, clique em **Adicionar Ponto de Conexão** para exibir o [Assistente para Implementação de Ponto de Conexão](../ide/implement-connection-point-wizard.md).

1. Selecione as interfaces do ponto de conexão a serem implementadas nas bibliotecas de tipos apropriadas e clique em **Concluir**.

1. Em Modo de Exibição de Classe, examine as classes proxy criadas para cada ponto de conexão. As classes são exibidas como CProxy*InterfaceName*\<T> e são derivadas de [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md).

1. Clique duas vezes na classe do ponto de conexão para exibir a definição da classe do ponto de conexão.

   - Se você implementar um ponto de conexão para a interface de seu próprio projeto, a seguinte definição será exibida

        ```
        template< class T >
        class CProxyInterfaceName :
           public IConnectionPointImpl< T, &IID_InterfaceName >
        {
        public:
        };
        ```

         If you implement a local interface, methods and properties appear in the class body.

   - Se você implementar um ponto de conexão para outra interface, a definição incluirá os métodos da interface, cada um precedido por `Fire_`.

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)<br>
[Adicionando pontos de conexão a um objeto](../atl/adding-connection-points-to-an-object.md)