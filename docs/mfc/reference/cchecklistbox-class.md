---
title: "Classe de CCheckListBox | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CCheckListBox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CCheckListBox"
  - "caixas de lista de verificação"
ms.assetid: 1dd78438-00e8-441c-b36f-9c4f9ac0d019
caps.latest.revision: 26
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CCheckListBox
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de uma caixa de lista de verificação do windows.  
  
## Sintaxe  
  
```  
  
class CCheckListBox : public CListBox  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCheckListBox::CCheckListBox](../Topic/CCheckListBox::CCheckListBox.md)|Constrói um objeto de `CCheckListBox` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCheckListBox::Create](../Topic/CCheckListBox::Create.md)|Cria a caixa de lista de verificação do windows e anexá\-la ao objeto de `CCheckListBox` .|  
|[CCheckListBox::DrawItem](../Topic/CCheckListBox::DrawItem.md)|Chamado pela estrutura quando uma aparência visual de uma caixa de lista do proprietário alterar.|  
|[CCheckListBox::Enable](../Topic/CCheckListBox::Enable.md)|Habilita ou desabilita um item da caixa de lista de verificação.|  
|[CCheckListBox::GetCheck](../Topic/CCheckListBox::GetCheck.md)|Obtém o estado da caixa de seleção de um item.|  
|[CCheckListBox::GetCheckStyle](../Topic/CCheckListBox::GetCheckStyle.md)|Obtém o estilo das caixas de seleção do controle.|  
|[CCheckListBox::IsEnabled](../Topic/CCheckListBox::IsEnabled.md)|Determina se um item está habilitado.|  
|[CCheckListBox::MeasureItem](../Topic/CCheckListBox::MeasureItem.md)|Chamado pela estrutura quando uma caixa de listagem com um estilo do proprietário é criada.|  
|[CCheckListBox::OnGetCheckPosition](../Topic/CCheckListBox::OnGetCheckPosition.md)|Chamado pela estrutura para obter a posição da caixa de seleção de um item.|  
|[CCheckListBox::SetCheck](../Topic/CCheckListBox::SetCheck.md)|Define o estado da caixa de seleção de um item.|  
|[CCheckListBox::SetCheckStyle](../Topic/CCheckListBox::SetCheckStyle.md)|Defina o estilo das caixas de seleção do controle.|  
  
## Comentários  
 “Uma caixa de lista de verificação” exibe uma lista de itens, como nomes de arquivo.  Cada item na lista possui uma caixa de seleção próxima a ela que o usuário pode verificar ou desmarque.  
  
 `CCheckListBox` é somente para controles proprietário desenhados como a lista contém mais de cadeias de caracteres de texto.  Em a sua forma mais simples, uma caixa de lista de verificação contém cadeias de caracteres de texto e caixas de seleção, mas você não precisa ter o texto de qualquer.  Por exemplo, você poderia ter uma lista de bitmaps pequenos com uma caixa de seleção ao lado de cada item.  
  
 Para criar sua própria caixa de lista de verificação, você deve derivar sua própria classe de `CCheckListBox`.  Para derivar sua própria classe, escreva um construtor para a classe derivada, então chamar **Criar**.  
  
 Se você desejar manipular as notificações do windows enviadas por uma caixa de listagem ao seu pai \(geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)\), adicionar uma função de membro de entrada e de mensagem\- manipulador de mensagem\- mapa para a classe pai para cada mensagem.  
  
 Cada entrada de mapa mensagem\- tem a seguinte forma:  
  
 Notificação**\(**`id`de**ON\_**, `memberFxn`**\)**  
  
 onde `id` especifica a identificação da janela filho do controle que envia a notificação e são `memberFxn` o nome da função de membro que você escreveu pai para trate a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 **afx\_msg** `void` `memberFxn` **\( \);**  
  
 Há apenas uma entrada de mapa mensagem\- que pertencem especificamente a **CcheckListBox** \(mas também consulte as entradas de mapa mensagem\- para [CListBox](../Topic/CListBox%20Class.md)\):  
  
-   **ON\_CLBN\_CHKCHANGE** o usuário alterou o estado da caixa de seleção de um item.  
  
 Se sua caixa de lista de verificação é uma caixa padrão de lista de verificação \(uma lista de cadeias de caracteres com as caixas de seleção opção\- dimensionadas à esquerda de cada\), você pode usar a opção [CCheckListBox::DrawItem](../Topic/CCheckListBox::DrawItem.md) para desenhar a caixa de lista de verificação.  Caso contrário, você deve substituir a função de [CListBox::CompareItem](../Topic/CListBox::CompareItem.md) e funções de [CCheckListBox::DrawItem](../Topic/CCheckListBox::DrawItem.md) e de [CCheckListBox::MeasureItem](../Topic/CCheckListBox::MeasureItem.md) .  
  
 Você pode criar uma caixa de lista de verificação de um modelo na caixa de diálogo ou diretamente no seu código.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CListBox](../Topic/CListBox%20Class.md)  
  
 `CCheckListBox`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Exemplo TSTCON MFC](../../top/visual-cpp-samples.md)   
 [Classe de CListBox](../Topic/CListBox%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CListBox](../Topic/CListBox%20Class.md)