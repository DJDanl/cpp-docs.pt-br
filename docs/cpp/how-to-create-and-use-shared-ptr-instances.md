---
title: "Como criar e usar inst&#226;ncias shared_ptr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 7d6ebb73-fa0d-4b0b-a528-bf05de96518e
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar e usar inst&#226;ncias shared_ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O tipo de `shared_ptr` é um ponteiro inteligente na biblioteca padrão do C\+\+ que é criada para cenários em que mais de um proprietário pode precisar gerenciar o tempo de vida do objeto na memória.  Depois que você inicialize `shared_ptr` que você pode copiar o, passa pelo valor nos argumentos da função, e atribuí\-lo a outras instâncias de `shared_ptr` .  Qualquer ponto das instâncias no mesmo objeto, e compartilha o acesso a um “bloco de controle” que incrementos e reduz que a contagem de referência sempre que `shared_ptr` novo é adicionado, sai do escopo, ou é redefinido.  Quando a contagem de referência chegar a zero, o bloco de controle exclui o recurso e próprio de memória.  
  
 A ilustração a seguir mostra várias instâncias de `shared_ptr` que aponte para um local de memória.  
  
 [![Ponteiro compartilhado](../Image/shared_ptr.png "shared\_ptr")](assetId:///9785ad08-31d8-411a-86a9-fb9cd9684c27)  
  
## Exemplo  
 Sempre que possível, use a função de [make\_shared](../Topic/make_shared%20\(%3Cmemory%3E\).md) para criar `shared_ptr` quando o recurso de memória é criado pela primeira vez.  `make_shared` exceções gerais é seguro.  Usa a mesma chamada para alocar memória para o bloco de controle e o recurso dessa maneira, e reduz a sobrecarga de compilação.  Se você não usar `make_shared`, utilize uma nova expressão explícita para criar o objeto antes do passar para o construtor de `shared_ptr` .  O exemplo a seguir mostra várias formas de declarar e inicializar `shared_ptr` junto com um novo objeto.  
  
 [!code-cpp[stl_smart_pointers#1](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_1.cpp)]  
  
## Exemplo  
 O exemplo a seguir mostra como declarar e inicializar as instâncias de `shared_ptr` que usam compartilhada na propriedade de um objeto que já foi atribuído por outro `shared_ptr`.  Suponha que `sp2` é `shared_ptr`inicializado.  
  
 [!code-cpp[stl_smart_pointers#2](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_2.cpp)]  
  
## Exemplo  
 `shared_ptr` também é útil em contêineres padrão de \(STL\) da biblioteca de modelo quando você estiver usando os algoritmos que copia os elementos.  Você pode envolver os elementos em `shared_ptr`, e copie\-o em outros contêineres com entendimento que a memória subjacente é válido à medida que o necessário, e mais.  O exemplo a seguir mostra como usar o algoritmo de `replace_copy_if` em instâncias de `shared_ptr` em um vetor.  
  
 [!code-cpp[stl_smart_pointers#4](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_3.cpp)]  
  
## Exemplo  
 Você pode usar `dynamic_pointer_cast`, `static_pointer_cast`, e `const_pointer_cast` para converter `shared_ptr`.  Essas funções lembram a `dynamic_cast`, a `static_cast`, e a operadores de `const_cast` .  O exemplo a seguir mostra como testar o tipo derivado de cada elemento em um vetor de `shared_ptr` das classes base, e copiar os elementos e exibir informações sobre eles.  
  
 [!code-cpp[stl_smart_pointers#5](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_4.cpp)]  
  
## Exemplo  
 Você pode passar `shared_ptr` para outra função das seguintes maneiras:  
  
-   Passe `shared_ptr` pelo valor.  Isso invoca o construtor de impressão, incrementa a contagem de referência, e torna o destinatário um proprietário.  Há uma pequena quantidade de sobrecarga nesta operação, que pode ser significante dependendo de quantos objetos de `shared_ptr` você estiver passando.  Use essa opção quando o contrato de código \(explícito ou implícito\) entre o chamador e o destinatário requer que o destinatário seja um proprietário.  
  
-   Passe `shared_ptr` por referência ou pela referência de const.  Nesse caso, a contagem de referência não é incrementada, e o destinatário pode acessar o ponteiro como o chamador não sair do escopo.  Ou, o destinatário pode decidir criar `shared_ptr` com base na referência, e se tornar bem assim em um proprietário compartilhado.  Use esta opção quando o chamador não tem conhecimento do destinatário, ou quando você deverá passar `shared_ptr` e deseja para evitar a operação de cópia por motivo de desempenho.  
  
-   Passar o ponteiro subjacente ou uma referência ao objeto subjacente.  Isso permite que o destinatário para usar o objeto, mas não permite compartilhar a propriedade ou estender o tempo de vida.  Se o destinatário cria `shared_ptr` do ponteiro bruto, nova `shared_ptr` é independente do original, e não controla o recurso subjacente.  Use essa opção quando o contrato entre o chamador e o destinatário claramente especifica que o chamador o reterá a propriedade de tempo de vida de `shared_ptr` .  
  
-   Quando você estiver decidindo como passar `shared_ptr`, determina se o destinatário tem que compartilhar a propriedade de recurso subjacente.  Um “owner” é um objeto ou função que possa manter o recurso subjacente ativo desde que o precisa.  Se o chamador precisa garantir que o destinatário pode estender a vida do ponteiro \(além de seu tempo de vida da função\), use a primeira opção.  Se você não precisa se preocupar se o destinatário estende o tempo de vida, a passagem por referência e deixe que o destinatário copie\-o ou não.  
  
-   Se você tem que fornecer a um auxiliar acesso da função ao ponteiro subjacente, e você souber que a função auxiliar apenas usará o ponteiro e retornará antes da função de chamada retornar, depois que a função não tem que compartilham a propriedade do ponteiro subjacente.  Somente precisa acessar o ponteiro no tempo de vida de `shared_ptr`do chamador.  Nesse caso, é seguro `shared_ptr` passar por referência, ou passar o ponteiro bruto ou uma referência ao objeto subjacente.  Transmitir essa maneira fornece um pequeno benefício de desempenho, e também pode ajudar a expressar a intenção de programação.  
  
-   Às vezes, por exemplo em `std:vector<shared_ptr<T>>`, você pode ter que transmitir cada `shared_ptr` a um corpo da expressão de lambda ou a um objeto denominado da função.  Se o lambda ou função não estiver armazenando o ponteiro, então passar `shared_ptr` em função da evitar invocar o construtor de cópia para cada elemento.  
  
 [!CODE [stl_smart_pointers#6](../CodeSnippet/VS_Snippets_Cpp/stl_smart_pointers#6)]  
  
## Exemplo  
 O exemplo a seguir mostra como `shared_ptr` sobrecarregar vários operadores de comparação para habilitar comparações de ponteiro na memória que pertence a instâncias de `shared_ptr` .  
  
 [!code-cpp[stl_smart_pointers#3](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_6.cpp)]  
  
## Consulte também  
 [Ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md)