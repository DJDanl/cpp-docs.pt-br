---
title: "Classe de COleVariant | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COleVariant"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Automação, tipos de parâmetro"
  - "Classe de COleVariant"
  - "Tipo de dados VARIANTE"
ms.assetid: e1b5cd4a-b066-4b9b-b48b-6215ed52d998
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleVariant
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula o tipo de dados de [VARIANTE](http://msdn.microsoft.com/pt-br/e305240e-9e11-4006-98cc-26f4932d2118) .  
  
## Sintaxe  
  
```  
class COleVariant : public tagVARIANT  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleVariant::COleVariant](../Topic/COleVariant::COleVariant.md)|Constrói um objeto de `COleVariant` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleVariant::Attach](../Topic/COleVariant::Attach.md)|Anexa **VARIANT** a `COleVariant`.|  
|[COleVariant::ChangeType](../Topic/COleVariant::ChangeType.md)|Altera o tipo variante de esse objeto de `COleVariant` .|  
|[COleVariant::Clear](../Topic/COleVariant::Clear.md)|Limpa este objeto de `COleVariant` .|  
|[COleVariant::Detach](../Topic/COleVariant::Detach.md)|Dispara **VARIANT** de `COleVariant` e retorna **VARIANT**.|  
|[COleVariant::GetByteArrayFromVariantArray](../Topic/COleVariant::GetByteArrayFromVariantArray.md)|Recupera uma matriz de bytes de uma matriz variante existente.|  
|[COleVariant::SetString](../Topic/COleVariant::SetString.md)|Defina a cadeia de caracteres para um tipo específico, normalmente ANSI.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleVariant::operator LPCVARIANT](../Topic/COleVariant::operator%20LPCVARIANT.md)|Converter um valor de `COleVariant` em `LPCVARIANT`.|  
|[COleVariant::operator LPVARIANT](../Topic/COleVariant::operator%20LPVARIANT.md)|Converte um objeto de `COleVariant` em `LPVARIANT`.|  
|[COleVariant::operator \=](../Topic/COleVariant::operator%20=.md)|Copia um valor de `COleVariant` .|  
|[\=\= De COleVariant::operator](../Topic/COleVariant::operator%20==.md)|Compara dois valores de `COleVariant` .|  
|[COleVariant::operator \<\<, \>\>](../Topic/COleVariant::operator%20%3C%3C,%20%3E%3E.md)|Produzir um valor de `COleVariant` a `CArchive` ou `CDumpContext` e entradas que `COleVariant` objetos de `CArchive`.|  
  
## Comentários  
 Este tipo de dados é usado na automação OLE.  Especificamente, a estrutura de [DISPPARAMS](http://msdn.microsoft.com/pt-br/a16e5a21-766e-4287-b039-13429aa78f8b) contém um ponteiro para um vetor de estruturas de **VARIANT** .  Uma estrutura de **DISPPARAMS** é usada para passar parâmetros para [IDispatch::Invoke](http://msdn.microsoft.com/pt-br/964ade8e-9d8a-4d32-bd47-aa678912a54d).  
  
> [!NOTE]
>  Essa classe é derivada da estrutura de **VARIANT** .  Isso significa que você pode passar `COleVariant` em um parâmetro que chamem para **VARIANT** e que os membros de dados de estrutura de **VARIANT** sejam acessíveis membros de dados de `COleVariant`.  
  
 As duas classes relacionadas [COleCurrency](../Topic/COleCurrency%20Class.md) MFC e [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) encapsula os tipos de dados variant **CONVERSOR DE MOEDAS** \(`VT_CY`\) e **DATE** \(`VT_DATE`\).  A classe de `COleVariant` são usadas amplamente nas classes de DAO; consulte essas classes para uso típico da classe, por exemplo [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 Para obter mais informações, consulte [VARIANTE](http://msdn.microsoft.com/pt-br/e305240e-9e11-4006-98cc-26f4932d2118), [CONVERSOR DE MOEDAS](http://msdn.microsoft.com/pt-br/5e81273c-7289-45c7-93c0-32c1553f708e), [DISPPARAMS](http://msdn.microsoft.com/pt-br/a16e5a21-766e-4287-b039-13429aa78f8b), e entradas de [IDispatch::Invoke](http://msdn.microsoft.com/pt-br/964ade8e-9d8a-4d32-bd47-aa678912a54d) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre a classe de `COleVariant` e seu uso em automação OLE, consulte “passar parâmetros na automação OLE” no artigo [automação](../../mfc/automation.md).  
  
## Hierarquia de herança  
 `tagVARIANT`  
  
 `COleVariant`  
  
## Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)