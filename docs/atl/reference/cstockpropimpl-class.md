---
title: "Classe de CStockPropImpl | Microsoft Docs"
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
  - "CStockPropImpl"
  - "ATL::CStockPropImpl"
  - "ATL.CStockPropImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [ATL], propriedades pré-definidas"
  - "Classe de CStockPropImpl"
  - "propriedades pré-definidas, controles ATL"
ms.assetid: 45f11d7d-6580-4a0e-872d-3bc8b836cfda
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStockPropImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para valores de propriedade conservados em estoque de suporte.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
class T,  
class InterfaceName,   
const IID* piid= &_ATL_IIDOF(InterfaceName),   
const GUID* plibid= &CComModule::m_libid,   
WORD wMajor= 1,  
WORD wMinor= 0,   
class tihclass= CcomTypeInfoHolder  
>  
class ATL_NO_VTABLE CStockPropImpl :  
public IDispatchImpl< InterfaceName, piid, plibid, wMajor,  
   wMinor, tihclass>  
```  
  
#### Parâmetros  
 `T`  
 A classe que implementa o controle e que deriva de `CStockPropImpl`.  
  
 `InterfaceName`  
 Uma interface dupla que expõe as propriedades pré\-definidas.  
  
 `piid`  
 Um ponteiro para o IID de `InterfaceName`.  
  
 `plibid`  
 Um ponteiro para o LIBID da biblioteca de tipos que contém a definição de `InterfaceName`.  
  
 `wMajor`  
 A versão principal de biblioteca de tipo.  o valor padrão é 1.  
  
 `wMinor`  
 A versão secundária de biblioteca de tipo.  o valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar informações de tipo para `T`.  o valor padrão é `CComTypeInfoHolder`.  
  
## Membros  
  
### Métodos públicos  
  
|||  
|-|-|  
|[get\_Appearance](../Topic/CStockPropImpl::get_Appearance.md)|Chamar esse método para obter o estilo de pintura usado pelo controle, por exemplo, por fundo ou por 3D.|  
|[get\_AutoSize](../Topic/CStockPropImpl::get_AutoSize.md)|Chamar esse método para obter o status do sinalizador que indica se o controle não pode ser qualquer outro tamanho.|  
|[get\_BackColor](../Topic/CStockPropImpl::get_BackColor.md)|Chamar esse método para obter a cor do plano de fundo do controle.|  
|[get\_BackStyle](../Topic/CStockPropImpl::get_BackStyle.md)|Chamar esse método para obter o estilo de plano de fundo do controle, transparente ou opaco.|  
|[get\_BorderColor](../Topic/CStockPropImpl::get_BorderColor.md)|Chamar esse método para obter a cor da borda do controle.|  
|[get\_BorderStyle](../Topic/CStockPropImpl::get_BorderStyle.md)|Chamar esse método para obter o estilo de borda do controle.|  
|[get\_BorderVisible](../Topic/CStockPropImpl::get_BorderVisible.md)|Chamar esse método para obter o status do sinalizador que indica se a borda do controle é visível ou não.|  
|[get\_BorderWidth](../Topic/CStockPropImpl::get_BorderWidth.md)|Chamar esse método para obter a largura \(em pixels\) da borda do controle.|  
|[get\_Caption](../Topic/CStockPropImpl::get_Caption.md)|Chamar esse método para obter o texto especificado na legenda de um objeto.|  
|[get\_DrawMode](../Topic/CStockPropImpl::get_DrawMode.md)|Chamar esse método para obter o modo de desenho do controle, por exemplo, caneta XOR ou para inverter cores.|  
|[get\_DrawStyle](../Topic/CStockPropImpl::get_DrawStyle.md)|Chamar esse método para obter o estilo de desenho do controle, por exemplo, sólido, tracejados, ou pontilhou\-o.|  
|[get\_DrawWidth](../Topic/CStockPropImpl::get_DrawWidth.md)|Chamar esse método para obter a largura de desenho \(em pixels\) usado pelos métodos de desenho do controle.|  
|[get\_Enabled](../Topic/CStockPropImpl::get_Enabled.md)|Chamar esse método para obter o status do sinalizador que indica se o controle está ativado.|  
|[get\_FillColor](../Topic/CStockPropImpl::get_FillColor.md)|Chamar esse método para obter a cor de preenchimento do controle.|  
|[get\_FillStyle](../Topic/CStockPropImpl::get_FillStyle.md)|Chamar esse método para obter o estilo de preenchimento do controle, por exemplo, sólido, transparente, ou hachurou\-o.|  
|[get\_Font](../Topic/CStockPropImpl::get_Font.md)|Chamar esse método para obter um ponteiro às propriedades da fonte do controle.|  
|[get\_ForeColor](../Topic/CStockPropImpl::get_ForeColor.md)|Chamar esse método para obter o primeiro plano a cor do controle.|  
|[get\_HWND](../Topic/CStockPropImpl::get_HWND.md)|Chamar esse método para obter o identificador de janela associado ao controle.|  
|[get\_MouseIcon](../Topic/CStockPropImpl::get_MouseIcon.md)|Chamar esse método para obter as propriedades de imagem de gráfico de bitmap ícone \(, ou metarquivo\) a ser exibido quando o mouse está sobre o controle.|  
|[get\_MousePointer](../Topic/CStockPropImpl::get_MousePointer.md)|Chamar esse método para obter o tipo de ponteiro do mouse exibido quando o mouse está sobre o controle, por exemplo, seta, cruz, ou ampulheta.|  
|[get\_Picture](../Topic/CStockPropImpl::get_Picture.md)|Chamar esse método para obter um ponteiro às propriedades de imagem de um gráfico \(ícone, bitmap, ou metarquivo\) a ser exibido.|  
|[get\_ReadyState](../Topic/CStockPropImpl::get_ReadyState.md)|Chamar esse método para obter o estado do controle pronto, por exemplo, carregar ou carregá\-lo.|  
|[get\_TabStop](../Topic/CStockPropImpl::get_TabStop.md)|Chamar esse método para obter o sinalizador que indica se o controle é uma parada de tabulação ou não.|  
|[get\_Text](../Topic/CStockPropImpl::get_Text.md)|Chamar esse método para obter o texto que é exibido com o controle.|  
|[get\_Valid](../Topic/CStockPropImpl::get_Valid.md)|Chamar esse método para obter o status do sinalizador que indica se o controle é válido ou não.|  
|[get\_Window](../Topic/CStockPropImpl::get_Window.md)|Chamar esse método para obter o identificador de janela associado ao controle.  Idêntico a [CStockPropImpl::get\_HWND](../Topic/CStockPropImpl::get_HWND.md).|  
|[put\_Appearance](../Topic/CStockPropImpl::put_Appearance.md)|Chamar esse método para definir o estilo de pintura usado pelo controle, por exemplo, por fundo ou por 3D.|  
|[put\_AutoSize](../Topic/CStockPropImpl::put_AutoSize.md)|Chamar esse método para definir o valor do sinalizador que indica se o controle não pode ser qualquer outro tamanho.|  
|[put\_BackColor](../Topic/CStockPropImpl::put_BackColor.md)|Chamar esse método para definir a cor do plano de fundo do controle.|  
|[put\_BackStyle](../Topic/CStockPropImpl::put_BackStyle.md)|Chamar esse método para definir o estilo de plano de fundo do controle.|  
|[put\_BorderColor](../Topic/CStockPropImpl::put_BorderColor.md)|Chamar esse método para definir a cor da borda do controle.|  
|[put\_BorderStyle](../Topic/CStockPropImpl::put_BorderStyle.md)|Chamar esse método para definir o estilo de borda do controle.|  
|[put\_BorderVisible](../Topic/CStockPropImpl::put_BorderVisible.md)|Chamar esse método para definir o valor do sinalizador que indica se a borda do controle é visível ou não.|  
|[put\_BorderWidth](../Topic/CStockPropImpl::put_BorderWidth.md)|Chamar esse método para definir a largura da borda do controle.|  
|[put\_Caption](../Topic/CStockPropImpl::put_Caption.md)|Chamar esse método para definir o texto a ser exibido com o controle.|  
|[put\_DrawMode](../Topic/CStockPropImpl::put_DrawMode.md)|Chamar esse método para definir o modo de desenho do controle, por exemplo, caneta XOR ou para inverter cores.|  
|[put\_DrawStyle](../Topic/CStockPropImpl::put_DrawStyle.md)|Chamar esse método para definir o estilo de desenho do controle, por exemplo, sólido, tracejados, ou pontilhou\-o.|  
|[put\_DrawWidth](../Topic/CStockPropImpl::put_DrawWidth.md)|Chamar esse método para definir a largura \(em pixels\) usada pelos métodos de desenho do controle.|  
|[put\_Enabled](../Topic/CStockPropImpl::put_Enabled.md)|Chamar esse método para definir o sinalizador que indica se o controle está ativado.|  
|[put\_FillColor](../Topic/CStockPropImpl::put_FillColor.md)|Chamar esse método para definir a cor de preenchimento do controle.|  
|[put\_FillStyle](../Topic/CStockPropImpl::put_FillStyle.md)|Chamar esse método para definir o estilo de preenchimento do controle, por exemplo, sólido, transparente, ou hachurou\-o.|  
|[put\_Font](../Topic/CStockPropImpl::put_Font.md)|Chamar esse método para definir as propriedades da fonte do controle.|  
|[put\_ForeColor](../Topic/CStockPropImpl::put_ForeColor.md)|Chamar esse método para definir primeiro plano a cor do controle.|  
|[put\_HWND](../Topic/CStockPropImpl::put_HWND.md)|Esse método retorna E\_FAIL.|  
|[put\_MouseIcon](../Topic/CStockPropImpl::put_MouseIcon.md)|Chamar esse método para definir as propriedades de imagem de gráfico de bitmap ícone \(, ou metarquivo\) a ser exibido quando o mouse está sobre o controle.|  
|[put\_MousePointer](../Topic/CStockPropImpl::put_MousePointer.md)|Chamar esse método para definir o tipo de ponteiro do mouse exibido quando o mouse está sobre o controle, por exemplo, seta, cruz, ou ampulheta.|  
|[put\_Picture](../Topic/CStockPropImpl::put_Picture.md)|Chamar esse método para definir as propriedades de imagem de um gráfico \(ícone, bitmap, ou metarquivo\) a ser exibido.|  
|[put\_ReadyState](../Topic/CStockPropImpl::put_ReadyState.md)|Chamar esse método para definir o estado do controle pronto, por exemplo, carregar ou carregá\-lo.|  
|[put\_TabStop](../Topic/CStockPropImpl::put_TabStop.md)|Chamar esse método para definir o valor do sinalizador que indica se o controle é uma parada de tabulação ou não.|  
|[put\_Text](../Topic/CStockPropImpl::put_Text.md)|Chamar esse método para definir o texto que é exibido com o controle.|  
|[put\_Valid](../Topic/CStockPropImpl::put_Valid.md)|Chamar esse método para definir o sinalizador que indica se o controle é válido ou não.|  
|[put\_Window](../Topic/CStockPropImpl::put_Window.md)|Este método chama [CStockPropImpl::put\_HWND](../Topic/CStockPropImpl::put_HWND.md), que retorna E\_FAIL.|  
|[putref\_Font](../Topic/CStockPropImpl::putref_Font.md)|Chamar esse método para definir as propriedades da fonte do controle, com uma contagem de referência.|  
|[putref\_MouseIcon](../Topic/CStockPropImpl::putref_MouseIcon.md)|Chamar esse método para definir as propriedades de imagem de gráfico de bitmap ícone \(, ou metarquivo\) a ser exibido quando o mouse está sobre o controle, com uma contagem de referência.|  
|[putref\_Picture](../Topic/CStockPropImpl::putref_Picture.md)|Chamar esse método para definir as propriedades de imagem de um gráfico \(ícone, bitmap, ou metarquivo\) a ser exibido, com uma contagem de referência.|  
  
## Comentários  
 `CStockPropImpl` fornece **put** e métodos de **get** para cada armazenam a propriedade.  Esses métodos fornecem código necessário obter ou definir o membro de dados associado com cada propriedade e notificá\-lo e sincronizar com o recipiente quando qualquer propriedade muda.  
  
 Visual C\+\+ fornece suporte para as propriedades pré\-definidas através de seus assistentes.  Para obter mais informações sobre como adicionar propriedades pré\-definidas a um controle, consulte [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md).  
  
 Para compatibilidade com versões anteriores, `CStockPropImpl` também expõe `get_Window` e métodos de `put_Window` que chamam apenas `get_HWND` e `put_HWND`, respectivamente.  a implementação padrão de `put_HWND` retorna **E\_FAIL** desde que `HWND` deve ser uma propriedade somente leitura.  
  
 As seguintes propriedades também têm uma implementação de **putref** :  
  
-   Fonte  
  
-   MouseIcon  
  
-   Imagem  
  
 As mesmas três propriedades pré\-definidas requerem que o membro de dados correspondente ser do tipo de `CComPtr` ou alguma outra classe que fornece contagem de referência da interface correta por meio de operador de atribuição.  
  
## Hierarquia de herança  
 `T`  
  
 [IDispatchImpl](../../atl/reference/idispatchimpl-class.md)  
  
 `CStockPropImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de IDispatchImpl](../../atl/reference/idispatchimpl-class.md)