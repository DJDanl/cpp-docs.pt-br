---
title: "_bstr_t::_bstr_t | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_bstr_t::_bstr_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe _bstr_t"
  - "Método _bstr_t"
  - "objeto BSTR"
ms.assetid: 116d994e-5a72-4351-afbe-866c80b4c165
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _bstr_t::_bstr_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Constrói um objeto `_bstr_t`.  
  
## Sintaxe  
  
```  
_bstr_t( ) throw( );   
_bstr_t(  
   const _bstr_t& s1   
) throw( );  
_bstr_t(  
   const char* s2   
);  
_bstr_t(  
   const wchar_t* s3   
);  
_bstr_t(  
   const _variant_t& var   
);  
_bstr_t(  
   BSTR bstr,  
   bool fCopy   
);  
```  
  
#### Parâmetros  
 `s1`  
 Um objeto `_bstr_t` a ser copiado.  
  
 `s2`  
 Uma cadeia de caracteres multibyte.  
  
 `s3`  
 Uma cadeia de caracteres Unicode  
  
 `var`  
 Um objeto [\_variant\_t](../cpp/variant-t-class.md).  
  
 `bstr`  
 Um objeto `BSTR` existente.  
  
 `fCopy`  
 Se `false`, o argumento `bstr` é anexado ao novo objeto sem que uma cópia seja feita chamando `SysAllocString`.  
  
## Comentários  
 A tabela a seguir descreve os construtores `_bstr_t`.  
  
|Construtor|Descrição|  
|----------------|---------------|  
|`_bstr_t( )`|Constrói um objeto padrão `_bstr_t` que encapsula um objeto `BSTR` nulo.|  
|`_bstr_t( _bstr_t&`  `s1`  `)`|Constrói um objeto `_bstr_t` como uma cópia de outro.<br /><br /> Essa é uma cópia *superficial*, que incrementa a contagem de referências do objeto `BSTR` encapsulado em vez de criar um novo.|  
|`_bstr_t( char*`  `s2`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá\-lo.<br /><br /> Esse construtor primeiro executa uma conversão de multibyte em Unicode.|  
|`_bstr_t( wchar_t*`  `s3`  `)`|Constrói um objeto `_bstr_t` chamando `SysAllocString` para criar um novo objeto `BSTR` e encapsulá\-lo.|  
|`_bstr_t( _variant_t&`  `var`  `)`|Constrói um objeto `_bstr_t` de um objeto `_variant_t` recuperando primeiro um objeto `BSTR` do objeto VARIANT encapsulado.|  
|`_bstr_t( BSTR`  `bstr` `, bool`  `fCopy`  `)`|Constrói um objeto `_bstr_t` de um `BSTR` existente \(em vez de uma cadeia de caracteres `wchar_t*`\).  Se `fCopy` é false, o `BSTR` fornecido é anexado ao novo objeto sem que uma cópia seja feita com `SysAllocString`.<br /><br /> Esse construtor é usado por funções wrapper nos cabeçalhos da biblioteca de tipos para encapsular e assumir a propriedade de `BSTR` que é retornada por um método de interface.|  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_bstr\_t](../cpp/bstr-t-class.md)   
 [Classe \_variant\_t](../cpp/variant-t-class.md)