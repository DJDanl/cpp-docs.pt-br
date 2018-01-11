---
title: "Adicionar Assistente de variável de membro | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.variable.overview
dev_langs: C++
helpviewer_keywords: Add Member Variable Wizard [C++]
ms.assetid: 73e8fa99-ac1a-42e2-8fc2-4684b9eb6d4d
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b909ec7ccd830e088df81ca0b2db8cda133c7a20
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="add-member-variable-wizard"></a>Assistente de Adição de Variável de Membro
Este assistente adiciona uma declaração de variável de membro para o arquivo de cabeçalho e, dependendo das opções, ela pode adicionar código ao arquivo. cpp. Depois de adicionar a variável de membro usando o assistente, você pode editar o código no ambiente de desenvolvimento.  
  
 **Access**  
 Define o acesso à variável de membro. Modificadores de acesso são palavras-chave que especificam o outras classes de acesso para a variável de membro. Consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md) para obter mais informações sobre como especificar o acesso. O nível de acesso a variáveis de membro é definido como **pública** por padrão.  
  
-   [public](../cpp/public-cpp.md)  
  
-   [protected](../cpp/protected-cpp.md)  
  
-   [private](../cpp/private-cpp.md)  
  
 **Tipo de variável**  
 Define o tipo de retorno para a variável de membro que você está adicionando.  
  
-   Se você estiver adicionando uma variável de membro que não é um controle de caixa de diálogo, selecione na lista de tipos disponíveis.  
  
     Para obter informações sobre os tipos, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
    |||  
    |-|-|  
    |`char`|**short**|  
    |**double**|`unsigned char`|  
    |**float**|`unsigned int`|  
    |`int`|`unsigned long`|  
    |**long**||  
  
-   Se você estiver adicionando uma variável de membro para um controle de caixa de diálogo, esta caixa é preenchida com o tipo do objeto retornado para um controle ou um valor. Se você selecionar **controle**, em seguida, **tipo de variável** Especifica a classe base do controle que você seleciona no **ID de controle** caixa. Se o controle de caixa de diálogo pode conter um valor, e se você selecionar **valor**, em seguida, **tipo de variável** Especifica o tipo apropriado para o valor de controle pode conter. Consulte [controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md) para obter mais informações.  
  
     Esse valor depende da seleção em **ID de controle** e não pode ser alterado.  
  
 **Nome da variável**  
 Define o nome da variável de membro que você está adicionando. Variáveis de membro normalmente começam com a cadeia de caracteres de identifica "m _," que é fornecido para você por padrão.  
  
 **Variável de controle**  
 Indica que a variável de membro gerencia um controle dentro de uma caixa de diálogo com [troca de dados e validação de dados](../mfc/dialog-data-exchange-and-validation.md) suporte. Consulte [DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) para obter mais informações. Essa opção está disponível apenas para variáveis de membro adicionadas para classes derivadas de [CDialog](../mfc/reference/cdialog-class.md). Marque esta caixa para ativar o **ID de controle** e **tipo de controle** opções.  
  
 **ID de controle**  
 Define a ID para a variável de controle que você está adicionando. Selecione na lista a ID do tipo de controle para o qual você está adicionando a variável de membro. A lista está ativo somente quando o **variável de controle** está selecionada, e ele é limitado a IDs para os controles que já foi adicionados à caixa de diálogo. Por exemplo, para o padrão **Okey** botão, a ID do controle é **IDOK**.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Controle**|Essa opção é definida por padrão para o tipo de controle. Ele gerencia o controle em si e não o estado ou conteúdo (que talvez você queira fazer com uma caixa de listagem, caixa de combinação ou caixa de edição) do controle.|  
|**Value**|Essa opção está disponível apenas para tipos de controle que podem conter um valor (como uma caixa de edição) ou refletir o estado (como uma caixa de seleção) e para o qual você pode gerenciar o intervalo, o conteúdo ou o estado. Consulte [controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md) para obter mais informações.|  
  
 **Categoria**  
 Especifica se a variável é baseada em um tipo de controle ou o valor do controle.  
  
 **Tipo de controle**  
 Define o tipo de controle que está sendo adicionado. Essa caixa não está disponível para alterar. Por exemplo, um botão tem o tipo de controle **botão**, e uma caixa de combinação tem o tipo de controle **COMBOBOX**. Consulte [controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md) para obter mais informações.  
  
 **Caracteres de max**  
 Disponível apenas quando **tipo de variável** é definido como [CString](../atl-mfc-shared/reference/cstringt-class.md). Indica o número máximo de caracteres que o controle pode conter.  
  
 **Valor mínimo**  
 Disponível apenas quando o tipo de variável é **BOOL**, `int`, **UINT**, **longo**, `DWORD`, **float**, **duplo**, **bytes**, **curto**, [COLECurrency](../mfc/reference/colecurrency-class.md) ou [CTime](../atl-mfc-shared/reference/ctime-class.md). Indica o menor valor aceitável para um intervalo de escala ou data.  
  
 **Valor máximo**  
 Disponível apenas quando o tipo de variável é **BOOL**, `int`, **UINT**, **longo**, `DWORD`, **float**, **duplo**, **bytes**, **curto**, `COLECurrency` ou `CTime`. Indica o maior valor aceitável para um intervalo de escala ou data.  
  
 **arquivo. h**  
 Para controles ActiveX, cujas variáveis de membro exigem uma classe wrapper. Define o nome do arquivo de cabeçalho para adicionar a declaração de classe.  
  
 **arquivo. cpp**  
 Para controles ActiveX, cujas variáveis de membro exigem uma classe wrapper. Define o nome do arquivo de implementação para adicionar a definição de classe.  
  
 **Comentário**  
 Fornece um comentário no arquivo de cabeçalho para a variável de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionar uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)