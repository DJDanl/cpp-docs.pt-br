---
title: "parcial (extens&#245;es de componentes C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "partial_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "partial"
  - "C + + / CX, parcial"
ms.assetid: 43adf1f5-10c5-44aa-a66f-7507e2bdabf8
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# parcial (extens&#245;es de componentes C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave `partial` permite que diferentes partes da mesma classe de referência sejam criadas independentemente e em arquivos diferentes.  
  
## Todos os Tempos de Execução  
 \(Este recurso de linguagem se aplica a [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]\).  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 Para uma classe de referência com duas definições parciais, a palavra\-chave `partial` é aplicada à primeira ocorrência da definição, e isso geralmente é feito por código gerado automaticamente, de modo que um codificador humano não use a palavra\-chave muito frequentemente.  Para todas as definições parciais subsequentes da classe, omita o modificador `partial` da palavra\-chave *class\-key* e o identificador de classe.  Quando o compilador encontra uma classe de referência e um identificador definidos anteriormente, mas nenhuma palavra\-chave `partial`, ele combina internamente todas as partes da definição de classe de referência em uma definição.  
  
### Sintaxe  
  
```cpp  
  
partial class-key identifier {  
   /* The first part of the partial class definition. This is typically auto-generated*/  
}  
// ...  
class-key identifier {  
   /* The subsequent part(s) of the class definition. The same identifier is specified, but the "partial" keyword is omitted. */  
}  
  
```  
  
### Parâmetros  
 *class\-key*  
 Uma palavra\-chave que declara uma classe ou estrutura com suporte do [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  `ref class`, `value class`, `ref struct` ou `value struct`.  
  
 *identifier*  
 O nome do tipo definido.  
  
### Comentários  
 Uma classe parcial que oferece suporte a cenários onde você modifica uma parte da definição de uma classe em um arquivo e software de geração de código automático — por exemplo, o designer XAML — também está modificando código na mesma classe.  Usando uma classe parcial, você pode impedir que o gerador de código automático substitua o seu código.  Em um projeto do Visual Studio, o modificador de `partial` é aplicado automaticamente ao arquivo gerado.  
  
 Conteúdo: com duas exceções, uma definição de classe parcial pode conter tudo que a definição de classe completa poderia conter se a palavra\-chave `partial` fosse omitida.  Porém, você não pode especificar a acessibilidade da classe \(por exemplo, `public partial class X {…};`\), ou `declspec`.  
  
 Os especificadores de acesso usados em uma definição de classe parcial para *identifier* não afetam a acessibilidade padrão em uma definição de classe completa ou parcial subsequente para *identifier*.  Definições embutidas de membros de dados estáticos são permitidas.  
  
 Declaração: Uma definição parcial de uma classe *identifier* apresenta apenas o nome *identifier*, mas *identifier* não pode ser usado de forma que requer uma definição de classe.  O nome *identifier* não pode ser usado para saber o tamanho de *identifier*, ou para usar uma base ou um membro de *identifier* até depois do compilador encontrar a definição completa de *identifier*.  
  
 Número e a ordenação: Pode haver definições de classe zero ou mais parciais para *identifier*.  Cada definição de classe parcial de *identifier* léxica deve preceder a uma definição completa de *identifier* \(se houver uma definição completa; caso contrário, a classe não pode ser usada exceto se declarado como frontal\) mas não precisa preceder instruções executadas de *identifier*.  Todas as chaves de classe devem corresponder.  
  
 Definição completa: No ponto da definição completa da classe *identifier*, o comportamento é igual a se a definição de *identifier* havia declarado todas as classes base, membros, etc. na ordem em que foram atendidos e definidos nas classes parciais.  
  
 Modelos: uma classe parcial não pode ser um modelo.  
  
 Genéricos: uma classe parcial poderá ser genérica se a definição completa puder ser genérica.  Mas todas as classes parciais e cheias devem ter exatamente os mesmos parâmetros genéricos, incluindo nomes de parâmetro formais.  
  
 Para obter mais informações sobre como usar a palavra\-chave de `partial` , consulte [Classes parciais \(C\+\+\/CX\)](http://go.microsoft.com/fwlink/p/?LinkId=249023).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 \(Este recurso de linguagem não se aplica ao Common Language Runtime\).  
  
## Consulte também  
 [Classes parciais \(C\+\+\/CX\)](http://go.microsoft.com/fwlink/p/?LinkId=249023)