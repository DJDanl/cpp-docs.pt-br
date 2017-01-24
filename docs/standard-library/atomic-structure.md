---
title: "Estrutura atomic | Microsoft Docs"
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
  - "atomic/std::atomic"
dev_langs: 
  - "C++"
ms.assetid: 261628ed-7049-41ac-99b9-cfe49f696b44
caps.latest.revision: 10
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura atomic
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que executa operações atômicas em um valor armazenado de tipo `Ty`.  
  
## Sintaxe  
  
```  
template <class Ty>  
struct atomic;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor atomic::atomic](../Topic/atomic::atomic%20Constructor.md)|Constrói um objeto atômico.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador atomic::operator Ty](../Topic/atomic::operator%20Ty%20Operator.md)|Lê e retorna o valor armazenado. \([Método atomic::load](../Topic/atomic::load%20Method.md)\)|  
|[Operador atomic::operator\=](../Topic/atomic::operator=%20Operator.md)|Usa um valor especificado para substituir o valor armazenado. \([Método atomic::store](../Topic/atomic::store%20Method.md)\)|  
|||  
|[Operador atomic::operator\+\+](../Topic/atomic::operator++%20Operator.md)|Aumenta o valor armazenado.  Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator\+\=](../Topic/atomic::operator+=%20Operator.md)|Adiciona um valor especificado ao valor armazenado.  Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator\-\-](../Topic/atomic::operator--%20Operator.md)|Diminui o valor armazenado.  Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator\-\=](../Topic/atomic::operator-=%20Operator.md)|Subtrai um valor especificado do valor armazenado.  Usado somente por especializações integrais e de ponteiro.|  
|[Operador atomic::operator&\=](../Topic/atomic::operator&=%20Operator.md)|Executa `and` bit a bit em um valor especificado e o valor armazenado.  Usado somente por especializações integrais.|  
|[Operador atomic::operator&#124;\=](../Topic/atomic::operator%7C=%20Operator.md)|Executa `or` bit a bit em um valor especificado e o valor armazenado.  Usado somente por especializações integrais.|  
|[Operador atomic::operator^\=](../Topic/atomic::operator%5E=%20Operator.md)|Executa `exclusive or` bit a bit em um valor especificado e o valor armazenado.  Usado somente por especializações integrais.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método atomic::compare\_exchange\_strong](../Topic/atomic::compare_exchange_strong%20Method.md)|Executa uma operação `atomic_compare_and_exchange` em `this` e retorna o resultado.|  
|[Método atomic::compare\_exchange\_weak](../Topic/atomic::compare_exchange_weak%20Method.md)|Executa uma `weak_atomic_compare_and_exchange` operação em `this` e retorna o resultado.|  
|[Método atomic::fetch\_add](../Topic/atomic::fetch_add%20Method.md)|Adiciona um valor especificado ao valor armazenado.|  
|[Método atomic::fetch\_and](../Topic/atomic::fetch_and%20Method.md)|Executa `and` bit a bit em um valor especificado e o valor armazenado.|  
|[Método atomic::fetch\_or](../Topic/atomic::fetch_or%20Method.md)|Executa `or` bit a bit em um valor especificado e o valor armazenado.|  
|[Método atomic::fetch\_sub](../Topic/atomic::fetch_sub%20Method.md)|Subtrai um valor especificado do valor armazenado.|  
|[Método atomic::fetch\_xor](../Topic/atomic::fetch_xor%20Method.md)|Executa `exclusive or` bit a bit em um valor especificado e o valor armazenado.|  
|[Método atomic::is\_lock\_free](../Topic/atomic::is_lock_free%20Method.md)|Especifica se as operações atômicas em `this` são *livre de bloqueio*.  Um tipo atômico será *livre de bloqueio* se nenhuma operação atômica nesse tipo usar bloqueios.|  
|[Método atomic::load](../Topic/atomic::load%20Method.md)|Lê e retorna o valor armazenado.|  
|[Método atomic::store](../Topic/atomic::store%20Method.md)|Usa um valor especificado para substituir o valor armazenado.|  
  
## Comentários  
 O tipo `Ty` deve ser *trivialmente copiável*.  Ou seja, o uso de [memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md) para copiar bytes deve gerar um objeto `Ty` válido que compare igual ao objeto original.  As funções de membro `compare_exchange_weak` e `compare_exchange_strong` usam [memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md) para determinar se dois valores `Ty` são iguais.  Essas funções não usarão um `operator==` definido por `Ty`.  As funções membro de `atomic` usam `memcpy` para copiar valores do tipo `Ty`.  
  
 Uma especialização parcial, `atomic<Ty *>`, existe para todos os tipos de ponteiro.  A especialização permite a adição de um deslocamento ao valor de ponteiro gerenciado ou à subtração de um deslocamento dela.  As operações aritméticas usam um argumento de tipo `ptrdiff_t` e ajustam esse argumento de acordo com o tamanho de `Ty` para que fique consistente com a aritmética de endereço comum.  
  
 Existe uma especialização para cada tipo integral, exceto `bool`.  Cada especialização fornece um vasto conjunto de métodos para operações aritméticas e lógicas atômicas.  
  
||||  
|-|-|-|  
|`atomic<char>`|`atomic<signed char>`|`atomic<unsigned char>`|  
|`atomic<char16_t>`|`atomic<char32_t>`|`atomic<wchar_t>`|  
|`atomic<short>`|`atomic<unsigned short>`|`atomic<int>`|  
|`atomic<unsigned int>`|`atomic<long>`|`atomic<unsigned long>`|  
|`atomic<long long>`|`atomic<unsigned long long>`|  
  
 As especializações integrais são derivadas dos tipos de `atomic_``integral`.  Por exemplo, `atomic<unsigned int>` é derivado de `atomic_uint`.  
  
## Requisitos  
 **Cabeçalho:** atômico  
  
 std de **Namespace:**  
  
## Consulte também  
 [\<atomic\>](../standard-library/atomic.md)   
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)