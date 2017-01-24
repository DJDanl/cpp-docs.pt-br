---
title: "&lt;chrono&gt; | Microsoft Docs"
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
  - "chrono/std::chrono::nanoseconds"
  - "chrono/std::chrono::minutes"
  - "chrono/std::chrono::seconds"
  - "<chrono>"
  - "chrono/std::chrono::hours"
  - "chrono/std::chrono::milliseconds"
  - "chrono/std::chrono::microseconds"
dev_langs: 
  - "C++"
ms.assetid: 844de749-f306-482e-89bc-6f53c99c8324
caps.latest.revision: 17
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;chrono&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inclua o cabeçalho \< chrono \> padrão para definir classes e funções que representam e manipulam as durações de tempo e instants de tempo.  
  
 **\(2015 do visual Studio:\)**a implementação de`steady_clock`foi alterado para atender aos requisitos padrão C\+\+ para steadiness e monotonicidade.  `steady_clock`Agora é baseado em QueryPerformanceCounter\(\) e`high_resolution_clock`agora é um typedef para`steady_clock`.  Como resultado, no Visual C\+\+`steady_clock::time_point`agora é um typedef para`chrono::time_point<steady_clock>`; no entanto, isso não é necessariamente o caso de outras implementações.  
  
## Sintaxe  
  
```cpp  
#include <chrono>  
```  
  
### Literais  
 Literais no cabeçalho \< chrono \> são membros do namespace literals::chrono\_literals embutido.  Para obter mais informações, consulte[literais chrono](../Topic/chrono%20literals.md).  
  
|||  
|-|-|  
|operador "" h \(unsigned long long Val\) operador "" h \(Val long double\)|Especifica que o valor representa horas.|  
|operador "" min \(unsigned long long Val\)  operador "" min \(Val long double\)|Especifica que o valor representa minutos.|  
|operador "" operador s \(unsigned long long Val\) "" s \(Val long double\)|Especifica que o valor representa segundos.|  
|operador "" ms \(unsigned long long Val\) operador "" ms \(Val long double\)|Especifica que o valor representa os milissegundos.|  
|operador "" us \(unsigned long long Val\) operador "" us \(Val long double\)|Especifica que o valor representa microssegundos.|  
|operador "" operador de ns \(unsigned long long Val\) "" ns \(Val long double\)|Especifica que o valor representa nanossegundos.|  
  
### Classes  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe duration](../standard-library/duration-class.md)|Descreve um tipo que contém um intervalo de tempo.|  
|[Classe time\_point](../standard-library/time-point-class.md)|Descreve um tipo que representa um ponto no tempo.|  
  
### Structs  
  
|Nome|Descrição|  
|----------|---------------|  
|[Estrutura common\_type](../standard-library/common-type-structure.md)|Descreve especializações da classe de modelo[common\_type](../standard-library/common-type-class.md)de instanciações de`duration`e`time_point`.|  
|[Estrutura duration\_values](../standard-library/duration-values-structure.md)|Fornece valores específicos para o`duration`parâmetro de modelo`Rep`.|  
|[Struct steady\_clock](../Topic/steady_clock%20struct.md)|Representa um`steady`relógio.|  
|[Estrutura system\_clock](../standard-library/system-clock-structure.md)|Representa uma*tipo de relógio*que se baseia no relógio do sistema em tempo real.|  
|[Estrutura treat\_as\_floating\_point](../standard-library/treat-as-floating-point-structure.md)|Especifica se um tipo pode ser tratado como um tipo de ponto flutuante.|  
  
### Funções  
  
|Nome|Descrição|  
|----------|---------------|  
|[Função duration\_cast](../Topic/duration_cast%20Function.md)|Conversões de uma`duration`objeto para um tipo especificado.|  
|[Função time\_point\_cast](../Topic/time_point_cast%20Function.md)|Conversões de uma`time_point`objeto para um tipo especificado.|  
  
### Operadores  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador operator\- \(STL\)](../Topic/operator-%20Operator%20\(STL\)1.md)|Operador de subtração ou negação de`duration`e`time_point`objetos.|  
|[Operador operator\!\= \(STL\)](../Topic/operator!=%20Operator%20\(STL\).md)|Operador de desigualdade que é usado com`duration`ou`time_point`objetos.|  
|[Módulo do operador \(STL\)](../Topic/operator%20modulo%20\(STL\).md)|Operador de módulo operações em`duration`objetos.|  
|[Operador operator\* \(STL\)](../Topic/operator*%20Operator%20\(STL\).md)|Operador de multiplicação para`duration`objetos.|  
|[Operador operator\/ \(STL\)](../Topic/operator-%20Operator%20\(STL\)2.md)|Operador de divisão para`duration`objetos.|  
|[Operador operator\+ \(STL\)](../Topic/operator+%20Operator%20\(STL\).md)|Adiciona`duration`e`time_point`objetos.|  
|[Operador operator\< \(STL\)](../Topic/operator%3C%20Operator%20\(STL\).md)|Determina se um`duration`ou`time_point`objeto é menor que outro`duration`ou`time_point`objeto.|  
|[Operador operator\<\= \(STL\)](../Topic/operator%3C=%20Operator%20\(STL\).md)|Determina se um`duration`ou`time_point`objeto é menor ou igual a outro`duration`ou`time_point`objeto.|  
|[Operador operator\=\= \(STL\)](../Topic/operator==%20Operator%20\(STL\).md)|Determina se dois`duration`objetos representam intervalos de tempo que têm o mesmo tamanho, ou se dois`time_point`objetos representam o mesmo ponto no tempo.|  
|[Operador operator\> \(STL\)](../Topic/operator%3E%20Operator%20\(STL\).md)|Determina se um`duration`ou`time_point`objeto é maior que outro`duration`ou`time_point`objeto.|  
|[Operador operator\>\= \(STL\)](../Topic/operator%3E=%20Operator%20\(STL\).md)|Determina se um`duration`ou`time_point`objeto é maior que ou igual a outro`duration`ou`time_point`objeto.|  
  
### Tipos predefinidos de duração  
 Para obter mais informações sobre tipos de taxa são usadas em definições de tipo as seguintes, consulte[\<ratio\>](../standard-library/ratio.md).  
  
|DefTipo|Descrição|  
|-------------|---------------|  
|`typedef duration<long long, nano> nanoseconds;`|Sinônimo de um`duration`tipo que tem um período de escala de um nanossegundo.|  
|`typedef duration<long long, micro> microseconds;`|Sinônimo de um`duration`tipo que tem um período de escala de um microssegundos.|  
|`typedef duration<long long, milli> milliseconds;`|Sinônimo de um`duration`tipo que tem um período de escala de um milissegundo.|  
|`typedef duration<long long> seconds;`|Sinônimo de um`duration`tipo que tem um período de escala de um segundo.|  
|`typedef duration<int, ratio<60> > minutes;`|Sinônimo de um`duration`tipo que tem um período de escala de um minuto.|  
|`typedef duration<int, ratio<3600> > hours;`|Sinônimo de um`duration`tipo que tem um período de escala de uma hora.|  
  
### Literais  
 **\(C \+ \+ 11\)**o cabeçalho \< chrono \> define os seguintes[literais definidos pelo usuário](../Topic/User-Defined%20Literals%20%20\(C++\).md)que você pode usar para maior conveniência, tipo de segurança e manutenção do seu código.  Esses literais são definidos na`literals::chrono_literals`namespace embutido e estão no escopo quando std::chrono está no escopo.  
  
|Literal|Descrição|  
|-------------|---------------|  
|operador chrono::Hours "" h \(unsigned long long Val\)|Especifica o horário como um valor integral.|  
|operador chrono::Duration \< double taxa \< 3600 \>\> "" h \(Val long double\)|Especifica o horário como um valor de ponto flutuante.|  
|chrono::minutes \(operador "" min\) \(unsigned long long Val\)|Especifica minutos como um valor integral.|  
|chrono::Duration \< double taxa \< 60 \>\> \(operador "" min\) \(Val duplo longo\)|Especifica minutos como um valor de ponto flutuante.|  
|operador chrono::seconds "" s \(unsigned long long Val\)|Especifica minutos como um valor integral.|  
|operador chrono::Duration \< double \> "" s \(Val long double\)|Especifica os segundos como um valor de ponto flutuante.|  
|operador chrono::milliseconds "" ms \(unsigned long long Val\)|Especifica milissegundos como um valor integral.|  
|operador chrono::Duration \< milli double \> "" ms \(Val long double\)|Especifica milissegundos como um valor de ponto flutuante.|  
|operador chrono::microseconds "" us \(unsigned long long Val\)|Especifica microssegundos como um valor integral.|  
|operador chrono::Duration \< micro double \> "" us \(Val long double\)|Especifica microssegundos como um valor de ponto flutuante.|  
|operador chrono::nanoseconds "" ns \(unsigned long long Val\)|Especifica nanossegundos como um valor integral.|  
|operador chrono::Duration \< nano double \> "" ns \(Val long double\)|Especifica nanossegundos como um valor de ponto flutuante.|  
|||  
  
## Comentários  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)