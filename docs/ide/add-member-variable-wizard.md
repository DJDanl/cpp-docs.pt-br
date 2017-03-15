---
title: "Assistente de Adi&#231;&#227;o de Vari&#225;vel de Membro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.variable.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Adição de Variável de Membro [C++]"
ms.assetid: 73e8fa99-ac1a-42e2-8fc2-4684b9eb6d4d
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de Adi&#231;&#227;o de Vari&#225;vel de Membro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este assistente adiciona uma declaração de variável de membro para o arquivo de cabeçalho e, dependendo das opções, ele pode adicionar código para o arquivo. cpp.  Depois de adicionar a variável de membro usando o assistente, você pode editar o código no ambiente de desenvolvimento.  
  
 **Access**  
 Define o acesso à variável de membro.  Modificadores de acesso são as palavras\-chave que especificam o acesso a que outras classes têm a variável de membro.  Consulte  [O controle de acesso de membro](../cpp/member-access-control-cpp.md) para obter mais informações sobre como especificar o acesso.  O nível de acesso a variáveis de membro é definido como  **pública** por padrão.  
  
-   [Público](../cpp/public-cpp.md)  
  
-   [Protegido](../Topic/protected%20\(C++\).md)  
  
-   [Particular](../Topic/private%20\(C++\).md)  
  
 **Tipo de variável**  
 Define o tipo de retorno para a variável de membro que você está adicionando.  
  
-   Se você estiver adicionando uma variável de membro não é um controle de caixa de diálogo, selecione na lista de tipos disponíveis.  
  
     Para obter informações sobre os tipos, consulte  [Tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
    |||  
    |-|-|  
    |`char`|**short**|  
    |**double**|`unsigned char`|  
    |**float**|`unsigned int`|  
    |`int`|`unsigned long`|  
    |**long**||  
  
-   Se você estiver adicionando uma variável de membro de um controle de caixa de diálogo, esta caixa é preenchida com o tipo de objeto retornado para um controle ou valor.  Se você selecionar  **controle**, em seguida,  **tipo de variável** Especifica a classe base do controle que você seleciona na  **Control ID** caixa.  Se o controle de caixa de diálogo pode conter um valor, e se você selecionar  **valor**, em seguida,  **tipo de variável** Especifica o tipo apropriado para o valor que o controle pode conter.  Consulte  [controles de caixa de diálogo e tipos de variáveis](../Topic/Dialog%20Box%20Controls%20and%20Variable%20Types.md) para obter mais informações.  
  
     Esse valor depende da seleção no  **ID de controle de** e não pode ser alterado.  
  
 **Nome da variável**  
 Define o nome da variável de membro que você está adicionando.  Variáveis de membro normalmente começam com a seqüência de caracteres de identificação "m \_," é fornecida para você por padrão.  
  
 **Variável de controle**  
 Indica que a variável de membro gerencia um controle dentro de uma caixa de diálogo com  [troca de dados e validação de dados](../mfc/dialog-data-exchange-and-validation.md) suporte.  Consulte  [DoDataExchange](../Topic/CWnd::DoDataExchange.md) para obter mais informações.  Esta opção só está disponível para variáveis de membros adicionadas às classes derivadas de  [CDialog](../mfc/reference/cdialog-class.md).  Marque esta caixa para ativar o  **ID de controle de** e  **tipo de controle** opções.  
  
 **Control ID** \(Identificação do controle\)  
 Define a identificação para a variável de controle que você está adicionando.  Selecione na lista a identificação do tipo de controle para o qual você está adicionando a variável de membro.  A lista está ativo somente quando o  **a variável de controle** está selecionada e é limitado as IDs dos controles já adicionado à caixa de diálogo.  Por exemplo, para o padrão  **OK** a identificação do controle de botão, é  **IDOK**.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Controle**|Essa opção é definida por padrão para o tipo de controle.  Ele gerencia o controle propriamente dito e não o estado ou conteúdo \(como você talvez queira fazer com uma caixa de listagem, caixa de combinação ou caixa de edição\) do controle.|  
|**Valor**|Essa opção está disponível somente para os tipos de controle que podem conter um valor \(como uma caixa de edição\) ou refletir um estado \(como, por exemplo, uma caixa de seleção\) e para o qual você pode gerenciar o intervalo, conteúdo ou estado.  Consulte  [controles de caixa de diálogo e tipos de variáveis](../Topic/Dialog%20Box%20Controls%20and%20Variable%20Types.md) para obter mais informações.|  
  
 **Category** \(Categoria\)  
 Especifica se a variável é baseada em um tipo de controle ou o valor do controle.  
  
 **Tipo de controle**  
 Define o tipo de controle que está sendo adicionado.  Esta caixa não está disponível para alterar.  Por exemplo, um botão tem o tipo de controle  **botão**, e uma caixa de combinação tem o tipo de controle  **COMBOBOX**.  Consulte  [controles de caixa de diálogo e tipos de variáveis](../Topic/Dialog%20Box%20Controls%20and%20Variable%20Types.md) para obter mais informações.  
  
 **Caracteres máx.**  
 Disponível somente quando  **tipo de variável** for definido como  [CString](../atl-mfc-shared/reference/cstringt-class.md).  Indica o número máximo de caracteres que o controle pode conter.  
  
 **Valor mínimo**  
 Available only when the variable type is **BOOL**, `int`, **UINT**, **long**, `DWORD`, **float**, **double**, **BYTE**, **short**, [COLECurrency](../Topic/COleCurrency%20Class.md) or [CTime](../Topic/CTime%20Class.md).  Indica o menor valor aceitável para um intervalo de data ou de escala.  
  
 **Valor máx.**  
 Available only when the variable type is **BOOL**, `int`, **UINT**, **long**, `DWORD`, **float**, **double**, **BYTE**, **short**, `COLECurrency` or `CTime`.  Indica o maior valor aceitável para um intervalo de data ou de escala.  
  
 **arquivo. h**  
 Para controles de ActiveX, cujas variáveis de membro exigem uma classe de wrapper.  Define o nome do arquivo de cabeçalho para adicionar a declaração de classe.  
  
 **arquivo. cpp**  
 Para controles de ActiveX, cujas variáveis de membro exigem uma classe de wrapper.  Define o nome do arquivo de implementação para adicionar a definição de classe.  
  
 **Comment**  
 Fornece um comentário no arquivo de cabeçalho para a variável de membro.  
  
## Consulte também  
 [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)