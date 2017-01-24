---
title: "Classe de CDumpContext | Microsoft Docs"
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
  - "CDumpContext"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Objeto de AfxDump"
  - "Classe de CDumpContext"
  - "diagnóstico, classes de diagnóstico"
  - "classes de diagnóstico"
  - "diagnósticos, classes de diagnóstico"
ms.assetid: 98c52b2d-14b5-48ed-b423-479a4d1c60fa
caps.latest.revision: 20
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDumpContext
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suporta livre orientaram saída de diagnóstico na forma de texto legível.  
  
## Sintaxe  
  
```  
class CDumpContext  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDumpContext::CDumpContext](../Topic/CDumpContext::CDumpContext.md)|Constrói um objeto de `CDumpContext` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDumpContext::DumpAsHex](../Topic/CDumpContext::DumpAsHex.md)|Despeja o item indicado em formato hexadecimal.|  
|[CDumpContext::Flush](../Topic/CDumpContext::Flush.md)|Libera os dados no buffer do contexto de um despejo.|  
|[CDumpContext::GetDepth](../Topic/CDumpContext::GetDepth.md)|Obtém um número inteiro que corresponde à profundidade de despejo.|  
|[CDumpContext::HexDump](../Topic/CDumpContext::HexDump.md)|Despeja os bytes contidos em uma matriz em formato hexadecimal.|  
|[CDumpContext::SetDepth](../Topic/CDumpContext::SetDepth.md)|Defina o tamanho de despejo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDumpContext::operator \<\<](../Topic/CDumpContext::operator%20%3C%3C.md)|Variáveis e objetos das inserções no contexto de despejo.|  
  
## Comentários  
 `CDumpContext` não tem uma classe base.  
  
 Você pode usar [afxDump](../Topic/afxDump%20\(CDumpContext%20in%20MFC\).md), um objeto predeclared de `CDumpContext` , para a maioria do seu despejo.  O objeto de `afxDump` está disponível somente na versão de depuração de biblioteca de classes da Microsoft foundation.  
  
 Vários de uso `afxDump` de [serviços diagnóstico](../Topic/Diagnostic%20Services.md) de memória para sua saída.  
  
 Em o ambiente do windows, a saída do objeto predefinido de `afxDump` , conceitualmente semelhante ao fluxo de `cerr` , são roteadas para o depurador através da função do windows **OutputDebugString**.  
  
 A classe de `CDumpContext` tem um operador sobrecarregado de inserção \(**\<\<**\) para ponteiros de `CObject` que despeje os dados do objeto.  Se você precisar de um despejo de formato personalizado para um objeto derivado de, substitua [CObject::Dump](../Topic/CObject::Dump.md).  A maioria da Microsoft foundation classes implementam uma função de membro de substituída `Dump` .  
  
 As classes que não são derivadas de `CObject`, como `CString`, `CTime`, e `CTimeSpan`, têm seus próprios operadores sobrecarregados de inserção de `CDumpContext` , como as estruturas são usados como **CFileStatus**, `CPoint`, e `CRect`.  
  
 Se você usar [IMPLEMENT\_DYNAMIC](../Topic/IMPLEMENT_DYNAMIC.md) ou macro de [IMPLEMENT\_SERIAL](../Topic/IMPLEMENT_SERIAL.md) na implementação da classe, então `CObject::Dump` será impresso o nome do seu `CObject`\- classe derivada.  Caso contrário, será impresso `CObject`.  
  
 A classe de `CDumpContext` está disponível através da depuração e versões de lançamento de biblioteca, mas a função de membro de `Dump` é definida apenas na versão de depuração.  Use **\#ifdef \_DEBUG** \/instruções de `#endif` para oferecer suporte ao código de diagnóstico, incluindo suas funções de membro personalizados de `Dump` .  
  
 Antes de criar seu próprio objeto de `CDumpContext` , você deve criar um objeto de `CFile` que serve como o destino de despejo.  
  
 Para obter mais informações sobre `CDumpContext`, consulte [Aplicativos MFC de depuração](../Topic/MFC%20Debugging%20Techniques.md).  
  
 **\_DEBUG de \#define**  
  
## Hierarquia de herança  
 `CDumpContext`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFile](../../mfc/reference/cfile-class.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)