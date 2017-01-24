---
title: "Classe type_info | Microsoft Docs"
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
  - "type_info"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe type_info"
  - "Classe type_info"
ms.assetid: 894ddda2-7de4-4da3-9404-d2c74e356c16
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe type_info
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe **type\_info** descreve as informações de tipo geradas no programa pelo compilador.  Os objetos dessa classe armazenam efetivamente um ponteiro para um nome do tipo.  A classe **type\_info** também armazena um valor codificado adequado à comparação de dois tipos para igualdade ou ordem de agrupamento.  As regras e a sequência de agrupamento de codificação para tipos não são especificados e podem ser diferentes entre os programas.  
  
 O \<`typeinfo>` arquivo de cabeçalho deve ser incluído para usar a classe **type\_info**.  A interface da classe **type\_info** é:  
  
```  
class type_info {  
public:  
    virtual ~type_info();  
    size_t hash_code() const  
    _CRTIMP_PURE bool operator==(const type_info& rhs) const;  
    _CRTIMP_PURE bool operator!=(const type_info& rhs) const;  
    _CRTIMP_PURE int before(const type_info& rhs) const;  
    _CRTIMP_PURE const char* name() const;  
    _CRTIMP_PURE const char* raw_name() const;  
};  
```  
  
 Você não pode instanciar objetos da classe **type\_info** diretamente, pois a classe tem apenas um construtor particular de cópia.  A única maneira de criar um objeto \(temporário\) **type\_info** é usar o operador [typeid](../cpp/typeid-operator.md).  Como o operador de atribuição também é particular, você não pode copiar ou atribuir objetos da classe **type\_info**.  
  
 **type\_info::hash\_code** define uma função de hash adequada para mapear valores de tipo **typeinfo** para uma distribuição de valores de índice.  
  
 Os operadores `==` e `!=` podem ser usados para ser comparado para fins de igualdade e desigualdade com outros objetos **type\_info**, respectivamente.  
  
 Não há nenhum link entre a ordem de agrupamento de tipos e relações de herança.  Use a função de membro **type\_info::before** para determinar a sequência de agrupamento de tipos.  Não há nenhuma garantia de que **type\_info::before** gerará o mesmo resultado em programas diferentes ou mesmo em execuções diferentes do mesmo programa.  Assim, **type\_info::before** é semelhante ao operador endereço de **\(&\)**.  
  
 A função de membro **type\_info::name** retorna **const char\*** a uma cadeia de caracteres com terminação nula que representa o nome legível do tipo.  A memória apontada é armazenada em cache e nunca deve ser desalocada diretamente.  
  
 A função de membro **type\_info::raw\_name** retorna **const char\*** a uma cadeia de caracteres com terminação nula que representa o nome decorado do tipo de objeto.  O nome é armazenado em sua forma decorada para economizar espaço.  Consequentemente, essa função é mais rápida que **type\_info::name** porque não precisa do nome não decorado.  A cadeia de caracteres retornada pela função **type\_info::raw\_name** é útil nas operações de comparação, mas não é legível.  Se você precisar de uma cadeia de caracteres legível, use a função **type\_info::name**.  
  
 As informações de tipo serão geradas para classes polimórficas apenas se a opção de compilador [\/GR \(Habilitar as informações de tipo de tempo de execução\)](../Topic/-GR%20\(Enable%20Run-Time%20Type%20Information\).md) for especificada.  
  
## Consulte também  
 [Informações de tipo de tempo de execução](../Topic/Run-Time%20Type%20Information.md)