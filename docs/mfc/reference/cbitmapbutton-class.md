---
title: "Classe de CBitmapButton | Microsoft Docs"
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
  - "CBitmapButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bitmaps, controles de botão"
  - "botões, bitmap"
  - "Classe de CBitmapButton"
ms.assetid: 9ad6cb45-c3c4-4fb1-96d3-1fe3df7bbcfc
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CBitmapButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria os controles de teclas rotuladas com imagens bitmap em vez de texto.  
  
## Sintaxe  
  
```  
class CBitmapButton : public CButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmapButton::CBitmapButton](../Topic/CBitmapButton::CBitmapButton.md)|Constrói um objeto de `CBitmapButton` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBitmapButton::AutoLoad](../Topic/CBitmapButton::AutoLoad.md)|Associa um botão em uma caixa de diálogo com um objeto da classe de `CBitmapButton` , carregar bitmaps pelo nome, e redimensiona o botão para ajustar o bitmap.|  
|[CBitmapButton::LoadBitmaps](../Topic/CBitmapButton::LoadBitmaps.md)|Inicializa o objeto carregando um ou mais recursos chamados do bitmap do arquivo de recurso do aplicativo e anexando\-o bitmaps ao objeto.|  
|[CBitmapButton::SizeToContent](../Topic/CBitmapButton::SizeToContent.md)|Redimensiona o botão para acomodar o projeto.|  
  
## Comentários  
 Os objetos de`CBitmapButton` contém até quatro bitmaps, que contêm imagens para os estados diferentes que um botão pode assumir: \(normal para cima ou para baixo\), \(ou\), focalizado atualmente selecionado, e desativado.  Somente o primeiro é necessário; bitmap o outro é opcional.  
  
 Imagens de Bitmap\- botão incluem a borda ao redor de imagem bem como a própria imagem.  A borda normalmente faz uma parte em mostrar o estado do botão.  Por exemplo, o bitmap para o estado em foco é geralmente como o para o estado para cima mas com um baixo\-relevo tracejada do retângulo da borda ou uma linha sólida grossa na borda.  O bitmap para o estado desativado geralmente é semelhante ao para o estado para cima mas tem um menor contraste \(como uma seleção de menu obscurecida ou esmaecida\).  
  
 Esses bitmaps podem ser de qualquer tamanho, mas todos eles são tratados como se fossem o mesmo tamanho que o bitmap para o estado para cima.  
  
 As combinações diferentes de estiver procurando de aplicativos de bitmap imagens:  
  
|Cima|Baixo|Focalizado|Desabilitado|Application|  
|----------|-----------|----------------|------------------|-----------------|  
|×||||Bitmap|  
|×|×|||Botão sem estilo de **WS\_TABSTOP**|  
|×|×|×|×|Botão da caixa de diálogo com todos os estados|  
|×|×|×||Botão da caixa de diálogo com estilo de **WS\_TABSTOP**|  
  
 A o criar um controle de bitmap\- botão, defina o estilo de **BS\_OWNERDRAW** para especificar que o botão proprietário é desenhado.  Isso faz com que o enviar mensagens de `WM_MEASUREITEM` e de `WM_DRAWITEM` para o botão; a estrutura trata essas mensagens e gerencia a aparência do botão para você.  
  
### Para criar um controle de bitmap\- botão na área cliente de uma janela  
  
1.  Crie um a quatro imagens de bitmap para o botão.  
  
2.  Construir o objeto de [CBitmapButton](../Topic/CBitmapButton::CBitmapButton.md) .  
  
3.  Chame a função de [Criar](../Topic/CButton::Create.md) para criar o controle de botão do windows para e anexá\-la ao objeto de `CBitmapButton` .  
  
4.  Chame a função de membro de [LoadBitmaps](../Topic/CBitmapButton::LoadBitmaps.md) para carregar os recursos de bitmap após o botão de bitmap é construído.  
  
### Para incluir um controle de bitmap\- botão em uma caixa de diálogo  
  
1.  Crie um a quatro imagens de bitmap para o botão.  
  
2.  Crie um modelo da caixa de diálogo com um botão do proprietário posicionado onde você deseja que o botão de bitmap.  O tamanho do botão no modelo não importa.  
  
3.  Definir a legenda do botão para um valor como “**MYIMAGE**” e define um símbolo para o botão como **IDC\_MYIMAGE**.  
  
4.  Em o script de recurso do aplicativo, dê cada uma das imagens criadas para o botão uma identificação construído acrescentar uma das letras “O”, “D”, “F”, ou “X” \(para cima, para baixo, focalizado desativado, e\) para a cadeia de caracteres usada para a legenda de botão na etapa 3.  Para a legenda “**MYIMAGE**do botão,” por exemplo, as identificações seria “**MYIMAGEU**”, “**MYIMAGED**”, “**MYIMAGEF**,” e “**MYIMAGEX**”. Você **must** especifica a identificação de seus bitmaps dentro de aspas duplas.  Se não o editor de recursos atribuir um inteiro para o recurso e o MFC falhará ao carregar a imagem.  
  
5.  Em a classe da caixa de diálogo do aplicativo \(derivada de `CDialog`\), adicionar um objeto de membro de `CBitmapButton` .  
  
6.  Em a rotina de [OnInitDialog](../Topic/CDialog::OnInitDialog.md) do objeto de `CDialog` , chame a função de [carregamento automático](../Topic/CBitmapButton::AutoLoad.md) do objeto de `CBitmapButton` , usando como parâmetros identificação do controle de botão e o ponteiro de **this** do objeto de `CDialog` .  
  
 Se você desejar manipular notificações do windows, como **BN\_CLICKED**, enviada por um controle de bitmap\- botão ao seu pai \(geralmente uma classe derivada de **CDialog\)**, adicione a `CDialog`objeto derivado de uma função de membro de entrada e de mensagem\- manipulador de mensagem\- mapa para cada mensagem.  As notificações enviadas por um objeto de `CBitmapButton` são as mesmas que aquelas fornecidas por um objeto de [CButton](../../mfc/reference/cbutton-class.md) .  
  
 A classe [CToolBar](../../mfc/reference/ctoolbar-class.md) usa uma abordagem diferentes para botões de bitmap.  
  
 Para obter mais informações sobre `CBitmapButton`, consulte[Controles](../../mfc/controls-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 `CBitmapButton`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [Exemplo CTRLTEST MFC](../../top/visual-cpp-samples.md)   
 [Classe de CButton](../../mfc/reference/cbutton-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)