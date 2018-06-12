---
title: Assistente de Adição de Variável de Membro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.variable.overview
dev_langs:
- C++
helpviewer_keywords:
- Add Member Variable Wizard [C++]
ms.assetid: 73e8fa99-ac1a-42e2-8fc2-4684b9eb6d4d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f3ae6a3aef4bdf774b5630a9bb0b2a0b49f7f29b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33336320"
---
# <a name="add-member-variable-wizard"></a>Assistente de Adição de Variável de Membro
Este assistente adiciona uma declaração de variável de membro ao arquivo de cabeçalho e, dependendo das opções, ele pode adicionar um código ao arquivo .cpp. Depois de adicionar a variável de membro usando o assistente, edite o código no ambiente de desenvolvimento.  
  
 **Access**  
 Define o acesso à variável de membro. Modificadores de acesso são palavras-chave que especificam o acesso que outras classes têm à variável de membro. Confira [Controle de acesso a membro](../cpp/member-access-control-cpp.md) para obter mais informações sobre como especificar o acesso. O nível de acesso da variável de membro é definido como **public** por padrão.  
  
-   [public](../cpp/public-cpp.md)  
  
-   [protected](../cpp/protected-cpp.md)  
  
-   [private](../cpp/private-cpp.md)  
  
 **Tipo de variável**  
 Define o tipo de retorno da variável de membro que está sendo adicionada.  
  
-   Se estiver adicionando uma variável de membro que não é um controle de caixa de diálogo, selecione uma opção na lista de tipos disponíveis.  
  
     Para obter informações sobre os tipos, confira [Tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
    |||  
    |-|-|  
    |`char`|**short**|  
    |**double**|`unsigned char`|  
    |**float**|`unsigned int`|  
    |`int`|`unsigned long`|  
    |**long**||  
  
-   Se estiver adicionando uma variável de membro a um controle de caixa de diálogo, essa caixa será preenchida com o tipo do objeto retornado para um controle ou um valor. Se você selecionar **Controle**, a opção **Tipo de variável** especificará a classe base do controle selecionado na caixa **ID de Controle**. Se o controle de caixa de diálogo puder conter um valor e você selecionar **Valor**, a opção **Tipo de variável** especificará o tipo apropriado para o valor que o controle pode conter. Confira [Controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md) para obter mais informações.  
  
     Esse valor depende da seleção em **ID de Controle** e não pode ser alterado.  
  
 **Nome da variável**  
 Define o nome da variável de membro que está sendo adicionada. Normalmente, as variáveis de membro começam com a cadeia de caracteres de identificação "m _", que é fornecida para você por padrão.  
  
 **Variável de controle**  
 Indica que a variável de membro gerencia um controle em uma caixa de diálogo com o suporte da [troca e validação de dados](../mfc/dialog-data-exchange-and-validation.md). Confira [DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) para obter mais informações. Essa opção está disponível somente para as variáveis de membro adicionadas às classes derivadas de [CDialog](../mfc/reference/cdialog-class.md). Marque essa caixa para ativar as opções **ID de Controle** e **Tipo de controle**.  
  
 **ID de Controle**  
 Define a ID para a variável de controle que está sendo adicionada. Selecione na lista a ID do tipo de controle ao qual a variável de membro está sendo adicionada. A lista fica ativa somente quando a caixa **Variável de controle** está selecionada e é limitada às IDs dos controles que já foram adicionados à caixa de diálogo. Por exemplo, para o botão **OK** padrão, a ID de Controle é **IDOK**.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Controle**|Essa opção está definida por padrão para o tipo de controle. Ela gerencia o controle em si e não o estado nem o conteúdo (como talvez você deseje fazer com uma caixa de listagem, caixa de combinação ou caixa de edição) do controle.|  
|**Value**|Essa opção está disponível somente para os tipos de controle que podem conter um valor (como uma caixa de edição) ou refletir um estado (como uma caixa de seleção) e para os quais você pode gerenciar o intervalo, o conteúdo ou o estado. Confira [Controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md) para obter mais informações.|  
  
 **Categoria**  
 Especifica se a variável baseia-se em um tipo de controle ou no valor do controle.  
  
 **Tipo de controle**  
 Define o tipo de controle que está sendo adicionado. Essa caixa não está disponível para alteração. Por exemplo, um botão tem o tipo de controle **BUTTON**, e uma caixa de combinação tem o tipo de controle **COMBOBOX**. Confira [Controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md) para obter mais informações.  
  
 **Número máx. de caracteres**  
 Disponível somente quando a opção **Tipo de variável** é definida como [CString](../atl-mfc-shared/reference/cstringt-class.md). Indica o número máximo de caracteres que o controle pode conter.  
  
 **Valor mín.**  
 Disponível somente quando o tipo de variável é **BOOL**, `int`, **UINT**, **long**, `DWORD`, **float**, **double**, **BYTE**, **short**, [COLECurrency](../mfc/reference/colecurrency-class.md) ou [CTime](../atl-mfc-shared/reference/ctime-class.md). Indica o menor valor aceitável para uma escala ou um intervalo de datas.  
  
 **Valor máx.**  
 Disponível somente quando o tipo de variável é **BOOL**, `int`, **UINT**, **long**, `DWORD`, **float**, **double**, **BYTE**, **short** `COLECurrency` ou `CTime`. Indica o maior valor aceitável para uma escala ou um intervalo de datas.  
  
 **Arquivo .h**  
 Para controles ActiveX, cujas variáveis de membro exigem uma classe wrapper. Define o nome do arquivo de cabeçalho para adicionar a declaração de classe.  
  
 **Arquivo .cpp**  
 Para controles ActiveX, cujas variáveis de membro exigem uma classe wrapper. Define o nome do arquivo de implementação para adicionar a definição de classe.  
  
 **Comentário**  
 Fornece um comentário no arquivo de cabeçalho da variável de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)