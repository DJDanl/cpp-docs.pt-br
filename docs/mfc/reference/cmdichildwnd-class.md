---
title: "Classe de CMDIChildWnd | Microsoft Docs"
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
  - "CMDIChildWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "janelas filho, Classe de CMDIChildWnd"
  - "Classe de CMDIChildWnd"
  - "MDI [C++], janelas filho"
  - "windows [C++], MDI"
ms.assetid: 6d07f5d4-9a3e-4723-9fa5-e65bb669fdd5
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMDIChildWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de uma janela filho de \(MDI\) de interface de documentos múltiplos do windows, juntamente com membros para gerenciar a janela.  
  
## Sintaxe  
  
```  
class CMDIChildWnd : public CFrameWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMDIChildWnd::CMDIChildWnd](../Topic/CMDIChildWnd::CMDIChildWnd.md)|Constrói um objeto de `CMDIChildWnd` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMDIChildWnd::Create](../Topic/CMDIChildWnd::Create.md)|Cria a janela filho MDI do windows associada com o objeto de `CMDIChildWnd` .|  
|[CMDIChildWnd::GetMDIFrame](../Topic/CMDIChildWnd::GetMDIFrame.md)|Retorna o elemento pai MDI da janela de cliente MDI.|  
|[CMDIChildWnd::MDIActivate](../Topic/CMDIChildWnd::MDIActivate.md)|Alterna a janela filho MDI.|  
|[CMDIChildWnd::MDIDestroy](../Topic/CMDIChildWnd::MDIDestroy.md)|Esta for a janela filho MDI.|  
|[CMDIChildWnd::MDIMaximize](../Topic/CMDIChildWnd::MDIMaximize.md)|Maximize esta janela filho MDI.|  
|[CMDIChildWnd::MDIRestore](../Topic/CMDIChildWnd::MDIRestore.md)|Restaura esta janela filho MDI de tamanho maximizado ou minimizado.|  
|[CMDIChildWnd::SetHandles](../Topic/CMDIChildWnd::SetHandles.md)|Defina as alças para recursos de menu e de aceleração.|  
  
## Comentários  
 Uma janela filho MDI tem bem como uma janela típica de quadro chave, exceto que a janela filho MDI aparece em uma janela do quadro MDI o invés da área de trabalho.  Uma janela filho MDI não tem uma barra de menus da própria, mas compartilha ao menu da janela do quadro MDI.  A estrutura altera automaticamente o menu do quadro MDI para representar a janela filho MDI ativa no momento.  
  
 Para criar uma janela filho MDI útil para seu aplicativo, derive uma classe de `CMDIChildWnd`.  Adicione variáveis de membros para a classe derivada para específico de armazenamento de dados ao seu aplicativo.  Implementar funções de membro de mensagem\- manipulador e um mapa de mensagem na classe derivada para especificar o que acontece quando as mensagens são todas direcionados para a janela.  
  
 Existem três maneiras para construir uma janela filho MDI:  
  
-   Construir\-la diretamente usando **Criar**.  
  
-   Construir\-la diretamente usando `LoadFrame`.  
  
-   Construir\-la indiretamente através de um modelo do documento.  
  
 Antes de você chamar **Criar** ou `LoadFrame`, você deve criar o objeto de quadro\- janela na heap usando o operador de **new** C\+\+.  Antes que chamar\-lhe **Criar** também pode registrar uma classe de janela com a função global de [AfxRegisterWndClass](../Topic/AfxRegisterWndClass.md) para definir estilos de ícone e da classe para o quadro.  
  
 Use a função de membro de **Criar** para passar parâmetros de criação do quadro como argumentos imediatos.  
  
 `LoadFrame` requer menos argumentos de **Criar**, e recupera o invés da maioria dos valores padrão de recursos, incluindo a legenda do quadro, o ícone, a tabela de aceleração, e o menu.  Para ser acessíveis por `LoadFrame`, todos esses recursos devem ter o mesmo número de identificação de recurso \(por exemplo, **IDR\_MAINFRAME**\).  
  
 Quando um objeto de `CMDIChildWnd` contém visões e documentos, eles são criados indiretamente pela estrutura em vez de diretamente pelo programador.  O objeto de `CDocTemplate` orquestra a criação de quadro chave, a criação de modos de exibição continente, e a conexão de modos de exibição ao documento apropriado.  Os parâmetros do construtor de `CDocTemplate` especificam `CRuntimeClass` das três classes envolvidas \(documento, quadro, e exibição\).  Um objeto de `CRuntimeClass` é usado pela estrutura para criar dinamicamente quando novos quadros especificado pelo usuário \(por exemplo, usando o comando novo Arquivo de comando ou da janela MDI o novo\).  
  
 Uma classe derivada de quadro\- janela de `CMDIChildWnd` deve ser declarada com `DECLARE_DYNCREATE` para que o mecanismo de `RUNTIME_CLASS` anterior funcione corretamente.  
  
 A classe herda de `CMDIChildWnd` grande parte da sua implementação padrão de `CFrameWnd`.  Para uma lista detalhada de esses recursos, por favor consulte a descrição da classe de [CFrameWnd](../../mfc/reference/cframewnd-class.md) .  A classe de `CMDIChildWnd` possui os seguintes recursos adicionais:  
  
-   Em conjunto com a classe de `CMultiDocTemplate` , vários objetos de `CMDIChildWnd` do mesmo modelo do documento compartilham o mesmo menu, salvando recursos do sistema do windows.  
  
-   O menu de janela filho ativa no momento MDI substitui totalmente o menu de janela do quadro MDI, e a legenda ativa no momento da janela filho MDI é adicionada à legenda da janela do quadro MDI.  Para os exemplos adicionais de funções de janela filho MDI que são implementadas em conjunto com uma janela de quadro MDI, consulte a descrição da classe de `CMDIFrameWnd` .  
  
 Não use o operador C\+\+ **delete** para destruir uma janela do quadro.  Use `CWnd::DestroyWindow` em vez de isso.  A implementação de `CFrameWnd` de `PostNcDestroy` excluirá o objeto C\+\+ quando a janela é destruída.  Quando o usuário fecha a janela do quadro, o manipulador padrão de `OnClose` chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CMDIChildWnd`, consulte [Molde o windows](../../mfc/frame-windows.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMDIChildWnd`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC prova MDI](../../top/visual-cpp-samples.md)   
 [Exemplo MDIDOCVW MFC](../../top/visual-cpp-samples.md)   
 [Exemplo SNAPVW MFC](../../top/visual-cpp-samples.md)   
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Classe de CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)