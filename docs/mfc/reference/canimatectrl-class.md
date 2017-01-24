---
title: "Classe de CAnimateCtrl | Microsoft Docs"
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
  - "CAnimateCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles de animação [C++], Classe de CAnimateCtrl"
  - "Classe de CAnimateCtrl"
  - "Controles comuns do Windows [C++], Classe de CAnimateCtrl"
ms.assetid: 5e8eb1bd-96b7-47b8-8de2-6bcbb3cc299b
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimateCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum de animação do windows.  
  
## Sintaxe  
  
```  
  
class CAnimateCtrl : public CWnd  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimateCtrl::CAnimateCtrl](../Topic/CAnimateCtrl::CAnimateCtrl.md)|Constrói um objeto de `CAnimateCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimateCtrl::Close](../Topic/CAnimateCtrl::Close.md)|Fecha o corte de AVI.|  
|[CAnimateCtrl::Create](../Topic/CAnimateCtrl::Create.md)|Cria um controle de animação e anexá\-la a um objeto de `CAnimateCtrl` .|  
|[CAnimateCtrl::CreateEx](../Topic/CAnimateCtrl::CreateEx.md)|Cria um controle de animação com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CAnimateCtrl` .|  
|[CAnimateCtrl::IsPlaying](../Topic/CAnimateCtrl::IsPlaying.md)|Indica se uma Audio\- Exibição intercalou corte de \(AVI\) está sendo executado.|  
|[CAnimateCtrl::Open](../Topic/CAnimateCtrl::Open.md)|Abre um clipe de AVI de um arquivo de som ou de um recurso e exibe o primeiro quadro.|  
|[CAnimateCtrl::Play](../Topic/CAnimateCtrl::Play.md)|Executa o corte de AVI sem som.|  
|[CAnimateCtrl::Seek](../Topic/CAnimateCtrl::Seek.md)|Exibe um único quadro selecionado de corte de AVI.|  
|[CAnimateCtrl::Stop](../Topic/CAnimateCtrl::Stop.md)|Para executar de corte de AVI.|  
  
## Comentários  
 Este controle \(e portanto a classe de `CAnimateCtrl` \) estão disponíveis somente para programas que executam na versão 3,51, Windows 95, Windows 98 e Windows NT e posterior.  
  
 Um controle de animação é uma janela retangular que exibe um corte no formato de AVI \(exibição de áudio intercalada\) a exibição do windows padrão\/formato de áudio.  Um clipe de AVI é uma série de quadros de bitmap, como um filme.  
  
 Os controles de animações podem executar somente clipes simples de AVI.  Especificamente, os clipes a ser executados por um controle de animação deve atender aos seguintes requisitos:  
  
-   Deve haver exatamente um fluxo de vídeo e deve ter pelo menos um quadro.  
  
-   Pode haver no máximo dois fluxos no arquivo \(normalmente outro fluxo, se presentes, é um fluxo de áudio, embora o controle de animação ignore informações de áudio\).  
  
-   Corte deve ser descompactado ou compactado com compactação RLE8.  
  
-   Nenhuma alteração de paleta é permitida no fluxo de vídeo.  
  
 Você pode adicionar corte de AVI ao seu aplicativo como um recurso de AVI, ou pode controlar o seu aplicativo como um arquivo separado de AVI.  
  
 Porque o thread continua a executar quando o corte de AVI é exibido, um uso comum para um controle de animação é indicar a atividade do sistema durante uma operação longa.  Por exemplo, a caixa de diálogo localizar de Arquivo Explorer exibe uma lupa em movimento como as pesquisas do sistema para um arquivo.  
  
 Se você criar um objeto de `CAnimateCtrl` de uma caixa de diálogo ou de um recurso da caixa de diálogo usando o editor de diálogo, será destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um objeto de `CAnimateCtrl` em uma janela, você pode precisar destrui\-la.  Se você criar o objeto de `CAnimateCtrl` na pilha, é automaticamente destruída.  Se você criar o objeto de `CAnimateCtrl` no heap usando a função de **new** , você deve chamar **delete** no objeto para destrui\-lo.  Se você derivado uma nova classe de `CAnimateCtrl` e atribui qualquer memória na classe, substitua o destrutor de `CAnimateCtrl` para descartar as alocações.  
  
 Para obter mais informações sobre como usar `CAnimateCtrl`, consulte [Controles](../../mfc/controls-mfc.md) e [usando CAnimateCtrl](../Topic/Using%20CAnimateCtrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CAnimateCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CAnimateCtrl::Create](../Topic/CAnimateCtrl::Create.md)   
 [ON\_CONTROL](../Topic/ON_CONTROL.md)